//--------------------------------------------------
// Dr. Art Hanna
// Mic1 Microassembler
//    8/15/2017
//    4/24/2018 1.1 added aliases for conditional JMPs
//                  added JMPT, JMPF to ISA (required no changes from 1.0)
//    4/19/2022 1.2 added support to compile multiple .mal files via input
//                  and use try/catch using invalid_argurment exceptions
//                  (by Azariel Del Carmen)
// Mic1Microassembler.cpp
//--------------------------------------------------
#define MIC1_VERSION "1.2 4/19/2022"

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

#define LINELENGTH               255
#define LINESPERPAGE              50
#define MAXLENGTHLABEL           128 
#define RESERVEDCSADDRESSUB    0X03F
#define MICROINSTRUCTIONLENGTH    42
#define SIZEOFCONTROLSTORE       512
#define EOLC                       1
#define EOFC                       2

//====================================================
typedef enum
//====================================================
{
    // pseudoterminals
    LABEL, HEXADDRESS, BITSTRING, LITERAL0, LITERAL1, LITERAL4,
    UNKNOWN,
    // reserved words
    SET,
    // TO,         // alias of EQUALSSIGN
    SVC,
    DONOTHING,
    ERROR,
    NOT,
    AND,
    OR,
    CMP,
    CMPU,
    GOTO,
    IF,
    THEN,
    ELSE,
    Z,
    P,
    N,
    JMPC,
    SL8,
    SRA1,
    SRL1,
    SL1,
    FETCH,
    READ,
    WRITE,
    H,
    OPC,        // T0 is alias
    TOS,
    CPP,
    LV,
    SP,
    PC,
    MDR,
    MAR,
    MBR,
    MBRU,
    // T0,         // alias of OPC
    T1,
    T2,
    T3,
    // delimiters and operators
    EOLTOKEN,   // EOLC
    EOFTOKEN,   // EOFC
    EQUALSSIGN, // = TO is alias
    PLUSSIGN,   // +
    MINUSSIGN   // -
} TOKEN;

/*
42-bit microinstruction format
B-Bus  Memory      C-Bus    Shift   ALU   JAM  nextAddress
 XXXX     XXX  XXXXXXXXXXXX XXXX XXXXXX  XXXX    XXXXXXXXX
                 1111111111 2222 222222  3333    333333444
 1234     567  890123456789 0123 456789  0123    456789012
*/
typedef char MICROINSTRUCTION[MICROINSTRUCTIONLENGTH + 1];

//====================================================
typedef struct
//====================================================
{
    int sourceLineNumber;
    char label[MAXLENGTHLABEL + 1];
    bool isFree;
    MICROINSTRUCTION microinstruction;
} CONTROLSTORE;

//====================================================
// Global identifiers
//====================================================
FILE* SOURCE, * LOG;
char  sourceFilename[80 + 1];
char  sourceLine[LINELENGTH + 1], nextCharacter;
int   sourceLineIndex, sourceLineNumber, endingSourceLineNumber, pageNumber;
bool  atEOF;
CONTROLSTORE controlStore[SIZEOFCONTROLSTORE];

//*************************************************************
int main()
//*************************************************************
{
    void DoPass1();
    void DoPass2();
    void DoPass3();
    void DoPass4();
    void CreateMic1MicrocodeFile();

    char fullFilename[80 + 1];
    char cont = 'n';

    printf("Mic1 Microassembler - Version %s\n\n", MIC1_VERSION);

    do {
        try {
            printf("Source filename? ");
            cin >> sourceFilename;
            strcpy(fullFilename, sourceFilename);
            strcat(fullFilename, ".mal");
            if ((SOURCE = fopen(fullFilename, "r")) == NULL)
            {
                throw invalid_argument("Cannot open given file name's Mic1 mal file.");
            }
            strcpy(fullFilename, sourceFilename);
            strcat(fullFilename, ".log");
            if ((LOG = fopen(fullFilename, "w")) == NULL)
            {
                throw invalid_argument("Cannot creating given file name's log file.");
            }

            // Initialize control store (*ALL* microcode bits are set during Pass #4)
            for (int address = 0X000; address <= SIZEOFCONTROLSTORE - 1; address++)
            {
                controlStore[address].sourceLineNumber = 0;
                controlStore[address].label[0] = '\0';
                controlStore[address].isFree = true;
            }

            DoPass1();
            DoPass2();
            DoPass3();
            DoPass4();
            fclose(SOURCE);

            CreateMic1MicrocodeFile();
            fclose(LOG);

            printf("Microassembled %s without errors\n", sourceFilename);
        }
        catch (const std::invalid_argument& e)
        {
            cout << "A invalid argurment exception has occurred: '" << e.what() << "'." << endl;
        }
        catch (const std::exception& e)
        {
            cout << "A unhandled exception has occurred: '" << e.what() << "'." << endl;
        }

        cout << "\nContinue Microassembling? (y/n): "; cin >> cont;
    } while (tolower(cont) == 'y');
    cout << "Exiting Microassembler." << endl;
    return(0);
}

//--------------------------------------------------
void DoPass1()
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    bool IsABlankOrCommentSourceLine();
    void PrintTopOfPageHeader();
    void PrintNakedSourceLine();
    void FindLabelInControlStore(char lexeme[], int& address, bool& found);
    int HexAddressToInt(char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    TOKEN token;
    char lexeme[LINELENGTH + 1];
    int address;

    /*
        Find *ALL* microinstructions with hexAddress because a control store address
           is not free when it is specified as the hexAddress of a microinstruction.
    */
    atEOF = false;
    sourceLineNumber = 0;
    pageNumber = 0;
    GetNextSourceLine();
    while (!atEOF)
    {
        sourceLineNumber++;
        if (sourceLineNumber % LINESPERPAGE == 1)
            PrintTopOfPageHeader();
        if (!IsABlankOrCommentSourceLine())
        {
            GetNextCharacter();
            GetNextToken(token, lexeme);
            if (token == HEXADDRESS)
            {
                address = HexAddressToInt(lexeme);
                if (controlStore[address].isFree)
                {
                    controlStore[address].isFree = false;
                    controlStore[address].sourceLineNumber = sourceLineNumber;
                }
                else
                    ProcessAssemblerError((char*)"Multiply-defined hexAddress");

                GetNextToken(token, lexeme);
                if (token == LABEL)
                {
                    int i, labelAddress;
                    bool found;

                    FindLabelInControlStore(lexeme, labelAddress, found);
                    if (!found)
                    {
                        char UCLexeme[MAXLENGTHLABEL + 1];
                        int i;

                        for (i = 0; i <= (int)strlen(lexeme); i++)
                            UCLexeme[i] = toupper(lexeme[i]);
                        strncpy(controlStore[address].label, UCLexeme, MAXLENGTHLABEL);
                    }
                    else
                        ProcessAssemblerError((char*)"Multiply-defined label");
                }
            }
        }
        PrintNakedSourceLine();
        GetNextSourceLine();
    }
    endingSourceLineNumber = sourceLineNumber;
}

//--------------------------------------------------
void DoPass2()
//--------------------------------------------------
{
    void TruncateLogFile();
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    bool IsABlankOrCommentSourceLine();
    void PrintTopOfPageHeader();
    void PrintNakedSourceLine();
    void FindLabelInControlStore(char lexeme[], int& address, bool& found);
    int HexAddressToInt(char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    TOKEN token;
    char lexeme[LINELENGTH + 1];

    TruncateLogFile();
    rewind(SOURCE);
    atEOF = false;
    sourceLineNumber = 0;
    pageNumber = 0;
    GetNextSourceLine();
    while (!atEOF)
    {
        int THENAddress, ELSEAddress;
        bool hasTHENAddress, hasELSEAddress;
        char THENLabel[LINELENGTH + 1], ELSELabel[LINELENGTH + 1];
        bool hasTHENLabel, hasELSELabel;

        sourceLineNumber++;
        if (sourceLineNumber % LINESPERPAGE == 1)
            PrintTopOfPageHeader();
        if (!IsABlankOrCommentSourceLine())
        {
            // Pass #2 solely concerned with then and else labels  
            hasTHENAddress = false;
            hasELSEAddress = false;
            hasTHENLabel = false;
            hasELSELabel = false;
            GetNextCharacter();
            GetNextToken(token, lexeme);
            while ((token != EOLTOKEN) && (token != IF))
                GetNextToken(token, lexeme);
            if (token == IF)
            {
                while ((token != EOLTOKEN) && (token != THEN))
                    GetNextToken(token, lexeme);
                if (token == THEN)
                {
                    GetNextToken(token, lexeme);
                    if (token == GOTO)
                        GetNextToken(token, lexeme);
                    if (token == HEXADDRESS)
                    {
                        hasTHENAddress = true;
                        THENAddress = HexAddressToInt(lexeme);
                    }
                    else if (token == LABEL)
                    {
                        int i;
                        bool found;

                        hasTHENLabel = true;
                        for (i = 0; i <= (int)strlen(lexeme); i++)
                            THENLabel[i] = toupper(lexeme[i]);
                        FindLabelInControlStore(THENLabel, THENAddress, hasTHENAddress);
                    }
                    else
                        ProcessAssemblerError((char*)"Expecting hexAddress or label");
                }
                else
                    ProcessAssemblerError((char*)"Expecting THEN");

                GetNextToken(token, lexeme);
                if (token == ELSE)
                {
                    GetNextToken(token, lexeme);
                    if (token == GOTO)
                        GetNextToken(token, lexeme);
                    if (token == HEXADDRESS)
                    {
                        hasELSEAddress = true;
                        ELSEAddress = HexAddressToInt(lexeme);
                    }
                    else if (token == LABEL)
                    {
                        int i;
                        bool found;

                        hasELSELabel = true;
                        for (i = 0; i <= (int)strlen(lexeme); i++)
                            ELSELabel[i] = toupper(lexeme[i]);
                        FindLabelInControlStore(ELSELabel, ELSEAddress, hasELSEAddress);
                    }
                    else
                        ProcessAssemblerError((char*)"Expecting hexAddress or label");
                }
                else
                    ProcessAssemblerError((char*)"Expecting ELSE");

                if (hasTHENAddress && hasELSEAddress)
                {
                    if (!((RESERVEDCSADDRESSUB < ELSEAddress) && (ELSEAddress < 0X100)))
                        ProcessAssemblerError((char*)"JAM ELSE microinstruction address out-of-range");
                    if (!(THENAddress > 0X100 + RESERVEDCSADDRESSUB))
                        ProcessAssemblerError((char*)"JAM THEN microinstruction address out-of-range");
                    if (ELSEAddress + 0X100 != THENAddress)
                        ProcessAssemblerError((char*)"JAM THEN microinstruction address != ELSE microinstruction address+0X100");
                }
                else if (!hasTHENAddress && hasELSEAddress)
                {
                    if (!((RESERVEDCSADDRESSUB < ELSEAddress) && (ELSEAddress < 0X100)))
                        ProcessAssemblerError((char*)"JAM ELSE microinstruction address out-of-range");
                    THENAddress = 0X100 + ELSEAddress;
                    if (controlStore[THENAddress].isFree)
                    {
                        controlStore[THENAddress].isFree = false;
                        strncpy(controlStore[THENAddress].label, THENLabel, MAXLENGTHLABEL);
                    }
                    else
                        ProcessAssemblerError((char*)"JAM THEN microinstruction address is unavailable");
                }
                else if (hasTHENAddress && !hasELSEAddress)
                {
                    if (!(THENAddress > 0X100 + RESERVEDCSADDRESSUB))
                        ProcessAssemblerError((char*)"JAM THEN microinstruction address out-of-range");
                    ELSEAddress = THENAddress - 0X100;
                    if (controlStore[ELSEAddress].isFree)
                    {
                        controlStore[ELSEAddress].isFree = false;
                        strncpy(controlStore[ELSEAddress].label, ELSELabel, MAXLENGTHLABEL);
                    }
                    else
                        ProcessAssemblerError((char*)"JAM ELSE microinstruction address is unavailable");
                }
                else//if ( !hasTHENAddress && !hasELSEAddress )
                {
                    bool found = false;

                    THENAddress = 0X100 + RESERVEDCSADDRESSUB + 1;
                    while (!found && (THENAddress <= SIZEOFCONTROLSTORE - 1))
                    {
                        if (controlStore[THENAddress - 0X100].isFree && controlStore[THENAddress].isFree)
                            found = true;
                        else
                            THENAddress++;
                    }
                    if (found)
                    {
                        ELSEAddress = THENAddress - 0X100;
                        controlStore[ELSEAddress].isFree = false;
                        strncpy(controlStore[ELSEAddress].label, ELSELabel, MAXLENGTHLABEL);
                        controlStore[THENAddress].isFree = false;
                        strncpy(controlStore[THENAddress].label, THENLabel, MAXLENGTHLABEL);
                    }
                    else
                        ProcessAssemblerError((char*)"JAM THEN/ELSE microinstruction address pair is unavailable");
                }
            }
        }
        PrintNakedSourceLine();
        GetNextSourceLine();
    }
}

//--------------------------------------------------
void DoPass3()
//--------------------------------------------------
{
    void TruncateLogFile();
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    bool IsABlankOrCommentSourceLine();
    void PrintTopOfPageHeader();
    void PrintNakedSourceLine();
    void FindLabelInControlStore(char lexeme[], int& address, bool& found);
    int HexAddressToInt(char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    TOKEN token;
    char lexeme[LINELENGTH + 1];

    TruncateLogFile();
    rewind(SOURCE);
    atEOF = false;
    sourceLineNumber = 0;
    pageNumber = 0;
    GetNextSourceLine();
    while (!atEOF)
    {
        sourceLineNumber++;
        if (sourceLineNumber % LINESPERPAGE == 1)
            PrintTopOfPageHeader();

        // Ensure that every microinstruction is allocated a control store address
        if (!IsABlankOrCommentSourceLine())
        {
            int address;
            bool hasAddress = false;
            bool hasLabel = false;
            bool found;

            GetNextCharacter();
            GetNextToken(token, lexeme);
            if (token == HEXADDRESS)
            {
                hasAddress = true;
                GetNextToken(token, lexeme);
            }
            if (token == LABEL)
            {
                int labelAddress;

                hasLabel = true;
                FindLabelInControlStore(lexeme, labelAddress, found);
                if (found)
                {
                    if ((controlStore[labelAddress].sourceLineNumber == 0) ||
                        (controlStore[labelAddress].sourceLineNumber == sourceLineNumber))
                    {
                        controlStore[labelAddress].sourceLineNumber = sourceLineNumber;
                        hasAddress = true;
                    }
                    else
                        ProcessAssemblerError((char*)"Multiply-defined label");
                }
            }
            if (!hasAddress)
            {
                found = false;
                address = RESERVEDCSADDRESSUB + 1;
                while (!found && (address <= SIZEOFCONTROLSTORE - 1))
                {
                    if (controlStore[address].isFree)
                        found = true;
                    else
                        address++;
                }
                if (found)
                {
                    controlStore[address].isFree = false;
                    controlStore[address].sourceLineNumber = sourceLineNumber;
                    if (hasLabel)
                    {
                        char UCLexeme[MAXLENGTHLABEL + 1];
                        int i;

                        for (i = 0; i <= (int)strlen(lexeme); i++)
                            UCLexeme[i] = toupper(lexeme[i]);
                        strncpy(controlStore[address].label, UCLexeme, MAXLENGTHLABEL);
                    }
                }
                else
                    ProcessAssemblerError((char*)"Control store capacity exceeded");
            }
        }
        PrintNakedSourceLine();
        GetNextSourceLine();
    }
}

//--------------------------------------------------
void DoPass4()
//--------------------------------------------------
{
    void TruncateLogFile();
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    bool IsABlankOrCommentSourceLine();
    void ALUControl(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void ShiftControl(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void Memory(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void NextAddress(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void PrintTopOfPageHeader();
    void PrintFullLine(int address, MICROINSTRUCTION microinstruction);
    void PrintNakedSourceLine();
    void ProcessAssemblerError(char errorMessage[]);

    TOKEN token;
    char lexeme[LINELENGTH + 1];
    int bit, address;

    TruncateLogFile();
    rewind(SOURCE);
    atEOF = false;
    sourceLineNumber = 0;
    pageNumber = 0;
    GetNextSourceLine();
    while (!atEOF)
    {
        sourceLineNumber++;
        if (sourceLineNumber % LINESPERPAGE == 1)
            PrintTopOfPageHeader();
        if (IsABlankOrCommentSourceLine())
            PrintNakedSourceLine();
        else
        {
            // Find control store address associated with microinstruction source line
            address = 0X000;
            while (!(controlStore[address].sourceLineNumber == sourceLineNumber))
                address++;
            /*
               Merely scan optional hexAddress and label fields, if present, because
                  they have been already parsed during passes 1, 2, and 3
            */
            GetNextCharacter();
            GetNextToken(token, lexeme);
            if (token == HEXADDRESS)
                GetNextToken(token, lexeme);
            if (token == LABEL)
                GetNextToken(token, lexeme);
            /*
               bitString COMPLETELY specifies a 42-bit microinstruction formatted

                           111111111122222222223333333333444
                  123456789012345678901234567890123456789012
                  BBBBMMMCCCCCCCCCCCCSSSSAAAAAAJJJJNNNNNNNNN
            */
            if (token == BITSTRING)
            {
                for (bit = 1; bit <= MICROINSTRUCTIONLENGTH; bit++)
                    controlStore[address].microinstruction[bit] = lexeme[bit - 1];
                GetNextToken(token, lexeme);
            }
            else
            {
                /*
                   Set *ALL* microinstruction bits to 0, then parse remaining
                      microinstruction fields, if specified (*Note* ALUControl is required,
                      but shiftControl, memory, and nextAddress are optional)
                */
                for (bit = 1; bit <= MICROINSTRUCTIONLENGTH; bit++)
                    controlStore[address].microinstruction[bit] = '0';

                ALUControl(token, lexeme, controlStore[address].microinstruction);

                if ((token == SL8) || (token == SRA1) || (token == SRL1) || (token == SL1))
                    ShiftControl(token, lexeme, controlStore[address].microinstruction);

                if ((token == FETCH) || (token == READ) || (token == WRITE))
                    Memory(token, lexeme, controlStore[address].microinstruction);

                if ((token == GOTO) || (token == IF) || (token == JMPC))
                    NextAddress(token, lexeme, controlStore[address].microinstruction);
                else
                {
                    /*
                       Determine nextAddress (since it is not explicitly specified) as the
                          address of the microinstruction on the next non-blank/non-comment
                          source line
                    */
                    int nextSourceLineNumber = sourceLineNumber + 1;
                    bool found = false;
                    int nextAddress, bit;

                    while (!found && (nextSourceLineNumber <= endingSourceLineNumber))
                    {
                        nextAddress = 0X000;
                        while (!found && (nextAddress <= SIZEOFCONTROLSTORE - 1))
                        {
                            if (controlStore[nextAddress].sourceLineNumber == nextSourceLineNumber)
                                found = true;
                            else
                                nextAddress++;
                        }
                        if (!found) nextSourceLineNumber++;
                    }
                    if (found)
                    {
                        for (bit = 42; bit >= 34; bit--)
                        {
                            controlStore[address].microinstruction[bit] = (nextAddress % 2 == 0) ? '0' : '1';
                            nextAddress /= 2;
                        }
                    }
                    else
                        ProcessAssemblerError((char*)"Expecting nextAddress field");
                    for (bit = 30; bit <= 33; bit++)
                        controlStore[address].microinstruction[bit] = '0';
                }
            }
            if (token != EOLTOKEN)
                ProcessAssemblerError((char*)"Expecting EOL");
            PrintFullLine(address, controlStore[address].microinstruction);
        }
        GetNextSourceLine();
    }

    // Check for undefined labels
    for (address = 0X000; address <= SIZEOFCONTROLSTORE - 1; address++)
    {
        if (!controlStore[address].isFree &&
            (controlStore[address].sourceLineNumber == 0) &&
            (strlen(controlStore[address].label) > 0))
        {
            char message[LINELENGTH + 1];

            sprintf(message, "Undefined label \"%s\"", controlStore[address].label);
            ProcessAssemblerError(message);
        }
    }
}

//--------------------------------------------------
void TruncateLogFile()
//--------------------------------------------------
{
    char fullFilename[80 + 1];

    fclose(LOG);
    strcpy(fullFilename, sourceFilename);
    strcat(fullFilename, ".log");
    if ((LOG = fopen(fullFilename, "w")) == NULL)
    {
        printf("Error opening log file ""%s"".\n", fullFilename);
        fclose(SOURCE);

        system("PAUSE");
        exit(1);
    }
}

//--------------------------------------------------
void ALUControl(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void ALUOperation(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void CBus(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void GetNextToken(TOKEN & token, char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    switch (token)
    {
    case SVC:
    {
        /*
           BBus = 0000, CBus = 000000000000, and shiftControl = 0000 are ignored by
              Mic1 during execution of the SVC pseudo ALUOperation = 000001
        */
        int bit;

        for (bit = 1; bit <= 4; bit++)
            microinstruction[bit] = '0';
        for (bit = 8; bit <= 19; bit++)
            microinstruction[bit] = '0';
        for (bit = 20; bit <= 23; bit++)
            microinstruction[bit] = '0';

        microinstruction[24] = '0';
        microinstruction[25] = '0';
        microinstruction[26] = '0';
        microinstruction[27] = '0';
        microinstruction[28] = '0';
        microinstruction[29] = '1';
        GetNextToken(token, lexeme);
        break;
    }
    case DONOTHING:
    {
        /*
           To do nothing, set BBus = 0000, CBus = 000000000000, shiftControl = 0000,
              and ALUOperation = 010000 (LITERAL0)
        */
        int bit;

        for (bit = 1; bit <= 4; bit++)
            microinstruction[bit] = '0';
        for (bit = 8; bit <= 19; bit++)
            microinstruction[bit] = '0';
        for (bit = 20; bit <= 23; bit++)
            microinstruction[bit] = '0';

        microinstruction[24] = '0';
        microinstruction[25] = '1';
        microinstruction[26] = '0';
        microinstruction[27] = '0';
        microinstruction[28] = '0';
        microinstruction[29] = '0';
        GetNextToken(token, lexeme);
        break;
    }
    case ERROR:
    {
        /*
           BBus = 0000, CBus = 000000000000, and shiftControl = 0000 are ignored by
              Mic1 during execution of the ERROR pseudo ALUOperation = 000100
        */
        int bit;

        for (bit = 1; bit <= 4; bit++)
            microinstruction[bit] = '0';
        for (bit = 8; bit <= 19; bit++)
            microinstruction[bit] = '0';
        for (bit = 20; bit <= 23; bit++)
            microinstruction[bit] = '0';

        microinstruction[24] = '0';
        microinstruction[25] = '0';
        microinstruction[26] = '0';
        microinstruction[27] = '1';
        microinstruction[28] = '0';
        microinstruction[29] = '0';
        GetNextToken(token, lexeme);
        break;
    }
    case SET:
        GetNextToken(token, lexeme);
        CBus(token, lexeme, microinstruction);
        if (token != EQUALSSIGN)
            ProcessAssemblerError((char*)"Expecting TO or =");
        GetNextToken(token, lexeme);
        ALUOperation(token, lexeme, microinstruction);
        break;
    default:
        ALUOperation(token, lexeme, microinstruction);
        break;
    }
}

//--------------------------------------------------
void CBus(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    do
    {
        switch (token)
        {
        case   H: microinstruction[8] = '1'; break;
        case OPC: microinstruction[9] = '1'; break;
        case TOS: microinstruction[10] = '1'; break;
        case CPP: microinstruction[11] = '1'; break;
        case  LV: microinstruction[12] = '1'; break;
        case  SP: microinstruction[13] = '1'; break;
        case  PC: microinstruction[14] = '1'; break;
        case MDR: microinstruction[15] = '1'; break;
        case MAR: microinstruction[16] = '1'; break;
        case  T1: microinstruction[17] = '1'; break;
        case  T2: microinstruction[18] = '1'; break;
        case  T3: microinstruction[19] = '1'; break;
        default:
            ProcessAssemblerError((char*)"Expecting C-Bus register");
        }
        GetNextToken(token, lexeme);
    } while ((token == H) ||
        (token == OPC) ||
        (token == TOS) ||
        (token == CPP) ||
        (token == LV) ||
        (token == SP) ||
        (token == PC) ||
        (token == MDR) ||
        (token == MAR) ||
        (token == T1) ||
        (token == T2) ||
        (token == T3));
}

//--------------------------------------------------
void ALUOperation(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void BBus(TOKEN & token, char lexeme[], MICROINSTRUCTION microinstruction);
    void ProcessAssemblerError(char errorMessage[]);

    int bit;
    char ALUOperationCode[6 + 1];

    switch (token)
    {
    case LITERAL0:
        strcpy(ALUOperationCode, "010000");                     // 0
        GetNextToken(token, lexeme);
        break;
    case LITERAL1:
        strcpy(ALUOperationCode, "010001");                     // 1
        GetNextToken(token, lexeme);
        break;
    case MINUSSIGN:
        GetNextToken(token, lexeme);
        if (token == H)
        {
            strcpy(ALUOperationCode, "111011");                  // -H
            GetNextToken(token, lexeme);
        }
        else if (token == LITERAL1)
        {
            strcpy(ALUOperationCode, "010010");                  // -1
            GetNextToken(token, lexeme);
        }
        else
            ProcessAssemblerError((char*)"Expecting H or 1");
        break;
    case NOT:
        GetNextToken(token, lexeme);
        if (token == H)
        {
            strcpy(ALUOperationCode, "011010");                  // not H
            GetNextToken(token, lexeme);
        }
        else
        {
            strcpy(ALUOperationCode, "101100");                  // not B
            BBus(token, lexeme, microinstruction);
        }
        break;
    case H:
        GetNextToken(token, lexeme);
        if (token == PLUSSIGN)
        {
            GetNextToken(token, lexeme);
            if (token == LITERAL1)
            {
                strcpy(ALUOperationCode, "111001");               // H + 1
                GetNextToken(token, lexeme);
            }
            else
            {
                BBus(token, lexeme, microinstruction);
                if (token == PLUSSIGN)
                {
                    GetNextToken(token, lexeme);
                    if (token == LITERAL1)
                    {
                        strcpy(ALUOperationCode, "111101");         // H + B + 1
                        GetNextToken(token, lexeme);
                    }
                    else
                        ProcessAssemblerError((char*)"Expecting 1");
                }
                else
                {
                    strcpy(ALUOperationCode, "111100");            // H + B
                }
            }
        }
        else if (token == AND)
        {
            strcpy(ALUOperationCode, "001100");                  // H and B
            GetNextToken(token, lexeme);
            BBus(token, lexeme, microinstruction);
        }
        else if (token == OR)
        {
            strcpy(ALUOperationCode, "011100");                  // H or B
            GetNextToken(token, lexeme);
            BBus(token, lexeme, microinstruction);
        }
        else if (token == CMP)
        {
            strcpy(ALUOperationCode, "000010");                  // H cmp B
            GetNextToken(token, lexeme);
            BBus(token, lexeme, microinstruction);
        }
        else if (token == CMPU)
        {
            strcpy(ALUOperationCode, "000011");                  // H cmpu B
            GetNextToken(token, lexeme);
            BBus(token, lexeme, microinstruction);
        }
        else
        {
            strcpy(ALUOperationCode, "011000");                  // H
        }
        break;
    default:
        BBus(token, lexeme, microinstruction);
        if (token == PLUSSIGN)
        {
            GetNextToken(token, lexeme);
            if (token == LITERAL1)
            {
                strcpy(ALUOperationCode, "110101");               // B + 1
                GetNextToken(token, lexeme);
            }
            else if (token == LITERAL4)
            {
                strcpy(ALUOperationCode, "000101");               // B + 4
                GetNextToken(token, lexeme);
            }
            else
                ProcessAssemblerError((char*)"Expecting 1");
        }
        else if (token == MINUSSIGN)
        {
            GetNextToken(token, lexeme);
            if (token == H)
            {
                strcpy(ALUOperationCode, "111111");               // B - H
                GetNextToken(token, lexeme);
            }
            else if (token == LITERAL1)
            {
                strcpy(ALUOperationCode, "110110");               // B - 1
                GetNextToken(token, lexeme);
            }
            else if (token == LITERAL4)
            {
                strcpy(ALUOperationCode, "000110");               // B - 4
                GetNextToken(token, lexeme);
            }
            else
                ProcessAssemblerError((char*)"Expecting H or 1");
        }
        else
        {
            strcpy(ALUOperationCode, "010100");                  // B
        }
        break;
    }
    for (bit = 24; bit <= 29; bit++)
        microinstruction[bit] = ALUOperationCode[bit - 24];
}

//--------------------------------------------------
void BBus(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    int bit;
    char BBusCode[4 + 1];

    switch (token)
    {
    case  MDR: strcpy(BBusCode, "0000"); break;
    case   PC: strcpy(BBusCode, "0001"); break;
    case  MBR: strcpy(BBusCode, "0010"); break;
    case MBRU: strcpy(BBusCode, "0011"); break;
    case   SP: strcpy(BBusCode, "0100"); break;
    case   LV: strcpy(BBusCode, "0101"); break;
    case  CPP: strcpy(BBusCode, "0110"); break;
    case  TOS: strcpy(BBusCode, "0111"); break;
    case  OPC: strcpy(BBusCode, "1000"); break;
    case   T1: strcpy(BBusCode, "1001"); break;
    case   T2: strcpy(BBusCode, "1010"); break;
    case   T3: strcpy(BBusCode, "1011"); break;
    default:
        ProcessAssemblerError((char*)"Expecting B-Bus register");
    }
    GetNextToken(token, lexeme);
    for (bit = 1; bit <= 4; bit++)
        microinstruction[bit] = BBusCode[bit - 1];
}

//--------------------------------------------------
void ShiftControl(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);

    switch (token)
    {
    case SL8:
        microinstruction[20] = '1';
        GetNextToken(token, lexeme);
        break;
    case SRA1:
        microinstruction[21] = '1';
        GetNextToken(token, lexeme);
        break;
    case SRL1:
        microinstruction[22] = '1';
        GetNextToken(token, lexeme);
        break;
    case SL1:
        microinstruction[23] = '1';
        GetNextToken(token, lexeme);
        break;
    }
}

//--------------------------------------------------
void Memory(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    while ((token == FETCH) ||
        (token == READ) ||
        (token == WRITE))
    {
        switch (token)
        {
        case FETCH: microinstruction[5] = '1'; break;
        case  READ: microinstruction[6] = '1'; break;
        case WRITE: microinstruction[7] = '1'; break;
        }
        GetNextToken(token, lexeme);
    }
    if ((microinstruction[6] == '1') && (microinstruction[7] == '1'))
        ProcessAssemblerError((char*)"Attempt to READ and WRITE memory at the same time");
}

//--------------------------------------------------
void NextAddress(TOKEN& token, char lexeme[], MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void FindLabelInControlStore(char lexeme[], int& address, bool& found);
    int HexAddressToInt(char lexeme[]);
    void ProcessAssemblerError(char errorMessage[]);

    int bit, nextAddress, THENAddress, ELSEAddress;
    char JAMCode[4 + 1];
    bool found;

    switch (token)
    {
    case GOTO:
        GetNextToken(token, lexeme);
        switch (token)
        {
        case HEXADDRESS:
            nextAddress = HexAddressToInt(lexeme);
            break;
        case LABEL:
            FindLabelInControlStore(lexeme, nextAddress, found);
            if (!found)
                ProcessAssemblerError((char*)"Undefined label");
            break;
        default:
            ProcessAssemblerError((char*)"Expecting hexAddress or label");
            break;
        }
        GetNextToken(token, lexeme);
        strcpy(JAMCode, "0000");
        break;
    case JMPC:
        GetNextToken(token, lexeme);
        if (token == HEXADDRESS)
            nextAddress = HexAddressToInt(lexeme);
        else
            ProcessAssemblerError((char*)"Expecting hexAddress");
        strcpy(JAMCode, "1000");
        GetNextToken(token, lexeme);
        break;
    case   IF:
        GetNextToken(token, lexeme);
        switch (token)
        {
        case   Z:
            strcpy(JAMCode, "0010");
            break;
        case   P:
            strcpy(JAMCode, "0001");
            break;
        case   N:
            strcpy(JAMCode, "0100");
            break;
        case NOT:
            GetNextToken(token, lexeme);
            switch (token)
            {
            case   Z:
                strcpy(JAMCode, "0101");
                break;
            case   P:
                strcpy(JAMCode, "0110");
                break;
            case   N:
                strcpy(JAMCode, "0011");
                break;
            default:
                ProcessAssemblerError((char*)"Expecting Z, P, or N");
                break;
            }
            break;
        default:
            ProcessAssemblerError((char*)"Expecting Z, P, N, or NOT");
            break;
        }
        GetNextToken(token, lexeme);
        if (token != THEN)
            ProcessAssemblerError((char*)"Expecting THEN");
        GetNextToken(token, lexeme);
        if (token == GOTO)
            GetNextToken(token, lexeme);
        switch (token)
        {
        case HEXADDRESS:
            THENAddress = HexAddressToInt(lexeme);
            break;
        case LABEL:
            FindLabelInControlStore(lexeme, THENAddress, found);
            break;
        default:
            ProcessAssemblerError((char*)"Expecting hexAddress or label");
            break;
        }
        GetNextToken(token, lexeme);
        if (token != ELSE)
            ProcessAssemblerError((char*)"Expecting ELSE");
        GetNextToken(token, lexeme);
        if (token == GOTO)
            GetNextToken(token, lexeme);
        switch (token)
        {
        case HEXADDRESS:
            ELSEAddress = HexAddressToInt(lexeme);
            break;
        case LABEL:
            FindLabelInControlStore(lexeme, ELSEAddress, found);
            break;
        default:
            ProcessAssemblerError((char*)"Expecting hexAddress or label");
            break;
        }
        nextAddress = ELSEAddress;
        // *ALL* semantic error checking done in Pass 2
        GetNextToken(token, lexeme);
        break;
    }
    for (bit = 30; bit <= 33; bit++)
        microinstruction[bit] = JAMCode[bit - 30];
    for (bit = 42; bit >= 34; bit--)
    {
        microinstruction[bit] = (nextAddress % 2 == 0) ? '0' : '1';
        nextAddress /= 2;
    }
}

//--------------------------------------------------
bool IsABlankOrCommentSourceLine()
//--------------------------------------------------
{
    /*
       sourceLine[] is blank line if it contains nothing but "white-space" and
          is a comment-only line if the first non-"white-space" character is '|'
    */
    bool IsWhiteSpaceCharacter(char character);

    int i;

    // Bypass "white-space"
    i = 0;
    while ((i <= ((int)strlen(sourceLine) - 1)) && IsWhiteSpaceCharacter(sourceLine[i]))
        i++;
    return((i > ((int)strlen(sourceLine) - 1)) || (sourceLine[i] == '|'));
}


//--------------------------------------------------
void CreateMic1MicrocodeFile()
//--------------------------------------------------
{
    char* HexInteger(int integer, int nibbles);

    FILE* MICROCODE;
    char fullFilename[80 + 1];
    int address, count;

    strcpy(fullFilename, sourceFilename);
    strcat(fullFilename, ".cs");
    if ((MICROCODE = fopen(fullFilename, "w")) == NULL)
    {
        printf("Error opening microcode file \"%s\".\n", fullFilename);
        system("PAUSE");
        exit(1);
    }
    count = 0;
    for (address = 0X000; address <= SIZEOFCONTROLSTORE - 1; address++)
    {
        if (!controlStore[address].isFree)
        {
            int bit;

            count++;
            // hex address
            fprintf(MICROCODE, "0X%03X:", address);
            // B-Bus
            fprintf(MICROCODE, " ");
            for (bit = 1; bit <= 4; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // memory
            fprintf(MICROCODE, " ");
            for (bit = 5; bit <= 7; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // C-Bus
            fprintf(MICROCODE, " ");
            for (bit = 8; bit <= 19; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // shift control
            fprintf(MICROCODE, " ");
            for (bit = 20; bit <= 23; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // ALU control
            for (bit = 24; bit <= 29; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // JAM bits
            fprintf(MICROCODE, " ");
            for (bit = 30; bit <= 33; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            // nextAddress
            fprintf(MICROCODE, " ");
            for (bit = 34; bit <= 42; bit++)
                fprintf(MICROCODE, "%c", controlStore[address].microinstruction[bit]);
            fprintf(MICROCODE, "\n");
        }
    }
    fclose(MICROCODE);
    printf("%3d microinstructions assembled\n", count);

    /*
    Address          0         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F
      0X000: AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA
      0X010: AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA
          .
          .
      0X1F0: AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA AAAAAAAAA

    Space used = XXX words
    */
    const char FF = 0X0C;

    pageNumber++;
    fprintf(LOG, "%cPage %3d  \"%s.mal\"\n\n", FF, pageNumber, sourceFilename);
    fprintf(LOG, "Address          0         1         2         3         4         5         6         7         8         9         A         B         C         D         E         F\n");
    for (address = 0X000; address <= SIZEOFCONTROLSTORE - 1; address++)
    {
        if (address % 16 == 0) fprintf(LOG, "  %5s:", HexInteger(address, 3));
        if (controlStore[address].isFree)
            fprintf(LOG, "          ");
        else if (strlen(controlStore[address].label) == 0)
            fprintf(LOG, " ---------");
        else
            fprintf(LOG, " %9s", controlStore[address].label);
        if (address % 16 == 15) fprintf(LOG, "\n");
    }
    fprintf(LOG, "\n%3d microinstructions assembled\n", count);
}

//--------------------------------------------------
char* HexInteger(int integer, int nibbles)
//--------------------------------------------------
{
    //   const char NIBBLES[] = "0123456789ABCDEF";
    // OR
    //   #define NIBBLES "0123456789ABCDEF"

    static char hex[2 + 8 + 1];

    hex[0] = '0'; hex[1] = 'X'; hex[nibbles + 2] = '\0';
    for (int i = nibbles; i >= 1; i--)
    {
        // ALLOWS
        //      hex[i+1] =  NIBBLES[ integer%16 ];
        // DID YOU KNOW YOU CAN DO THIS?!
        hex[i + 1] = "0123456789ABCDEF"[integer % 16];
        integer /= 16;
    }
    return(hex);
}

//--------------------------------------------------
void FindLabelInControlStore(char lexeme[], int& address, bool& found)
//--------------------------------------------------
{
    char UCLexeme[LINELENGTH + 1];
    int i;

    for (i = 0; i <= (int)strlen(lexeme); i++)
        UCLexeme[i] = toupper(lexeme[i]);
    found = false;
    address = 0;
    while (!found && (address <= SIZEOFCONTROLSTORE - 1))
    {
        if (strncmp(controlStore[address].label, UCLexeme, MAXLENGTHLABEL) == 0)
            found = true;
        else
            address += 1;
    }
}

//--------------------------------------------------
int HexAddressToInt(char lexeme[])
//--------------------------------------------------
{
    // hexAddress syntax is exactly 0X000-to-0X1FF
    int r;

    sscanf(lexeme, "%X", &r);
    return(r);
}

//--------------------------------------------------
bool IsWhiteSpaceCharacter(char character)
//--------------------------------------------------
{
    return((character == ' ')
        || (character == ';')
        || (character == ':')
        || (character == ',')
        || (character == '\t'));
}

//----------------------------------------------------
void PrintTopOfPageHeader()
//----------------------------------------------------
{
    /*
             11111111112222222222333333333344444444445555555555666666666677777777778
    12345678901234567890123456789012345678901234567890123456789012345678901234567890
    Page XXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

      MLC B-Bus Mem        C-Bus Shift    ALU  JAM nextAddress Line  Source Line
    ----- ----- --- ------------ ----- ------ ---- ----------- ----  --------------------------------------------------------------------------
    0XXXX  XXXX XXX XXXXXXXXXXXX  XXXX XXXXXX XXXX   XXXXXXXXX XXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    */
    const char FF = 0X0C;

    pageNumber++;
    fprintf(LOG, "%cPage %3d  \"%s.mal\"\n\n", FF, pageNumber, sourceFilename);
    fprintf(LOG, "  MLC B-Bus Mem        C-Bus Shift    ALU  JAM nextAddress Line  Source Line\n");
    fprintf(LOG, "----- ----- --- ------------ ----- ------ ---- ----------- ----  --------------------------------------------------------------------------\n");
    fflush(LOG);
}

//--------------------------------------------------
void PrintFullLine(int address, MICROINSTRUCTION microinstruction)
//--------------------------------------------------
{
    int bit;

    // hex address (microprogram location counter)
    fprintf(LOG, "0X%03X", address);
    // B-Bus
    fprintf(LOG, "  ");
    for (bit = 1; bit <= 4; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // memory
    fprintf(LOG, " ");
    for (bit = 5; bit <= 7; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // C-Bus
    fprintf(LOG, " ");
    for (bit = 8; bit <= 19; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // shift control
    fprintf(LOG, "  ");
    for (bit = 20; bit <= 23; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // ALU control
    fprintf(LOG, " ");
    for (bit = 24; bit <= 29; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // JAM bits
    fprintf(LOG, " ");
    for (bit = 30; bit <= 33; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);
    // nextAddress
    fprintf(LOG, "   ");
    for (bit = 34; bit <= 42; bit++)
        fprintf(LOG, "%c", microinstruction[bit]);

    fprintf(LOG, " ");
    fprintf(LOG, "%4d  %s\n", sourceLineNumber, sourceLine);
}

//--------------------------------------------------
void PrintNakedSourceLine()
//--------------------------------------------------
{
    fprintf(LOG, "                                                           ");
    fprintf(LOG, "%4d  %s\n", sourceLineNumber, sourceLine);
}

//--------------------------------------------------
void GetNextToken(TOKEN& token, char lexeme[])
//--------------------------------------------------
{
    void GetNextCharacter();
    bool IsWhiteSpaceCharacter(char character);
    void ProcessAssemblerError(char errorMessage[]);

    do
    {
        // "Eat" white-space
        while (IsWhiteSpaceCharacter(nextCharacter))
            GetNextCharacter();

        // "Eat" comments, if any. Comments are always assumed to extend to EOLC.
        if (nextCharacter == '|')
            do
                GetNextCharacter();
        while (nextCharacter != EOLC);
    } while (IsWhiteSpaceCharacter(nextCharacter));

    // Reserved words and label
    if (isalpha(nextCharacter))
    {
        int i;
        char UCLexeme[LINELENGTH + 1];

        i = 0;
        lexeme[i++] = nextCharacter;
        GetNextCharacter();
        while (isalpha(nextCharacter) || isdigit(nextCharacter))
        {
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
        }
        if (i > MAXLENGTHLABEL)
            i = MAXLENGTHLABEL;
        lexeme[i] = '\0';
        for (i = 0; i <= (int)strlen(lexeme); i++)
            UCLexeme[i] = toupper(lexeme[i]);
        if (strcmp(UCLexeme, "SET") == 0)
            token = SET;
        else if (strcmp(UCLexeme, "TO") == 0)
            // alias of EQUALSIGN
            token = EQUALSSIGN;
        else if (strcmp(UCLexeme, "SVC") == 0)
            token = SVC;
        else if (strcmp(UCLexeme, "DONOTHING") == 0)
            token = DONOTHING;
        else if (strcmp(UCLexeme, "ERROR") == 0)
            token = ERROR;
        else if (strcmp(UCLexeme, "NOT") == 0)
            token = NOT;
        else if (strcmp(UCLexeme, "AND") == 0)
            token = AND;
        else if (strcmp(UCLexeme, "OR") == 0)
            token = OR;
        else if (strcmp(UCLexeme, "CMP") == 0)
            token = CMP;
        else if (strcmp(UCLexeme, "CMPU") == 0)
            token = CMPU;
        else if (strcmp(UCLexeme, "GOTO") == 0)
            token = GOTO;
        else if (strcmp(UCLexeme, "IF") == 0)
            token = IF;
        else if (strcmp(UCLexeme, "THEN") == 0)
            token = THEN;
        else if (strcmp(UCLexeme, "ELSE") == 0)
            token = ELSE;
        else if (strcmp(UCLexeme, "Z") == 0)
            token = Z;
        else if (strcmp(UCLexeme, "P") == 0)
            token = P;
        else if (strcmp(UCLexeme, "N") == 0)
            token = N;
        else if (strcmp(UCLexeme, "JMPC") == 0)
            token = JMPC;
        else if (strcmp(UCLexeme, "SL8") == 0)
            token = SL8;
        else if (strcmp(UCLexeme, "SRA1") == 0)
            token = SRA1;
        else if (strcmp(UCLexeme, "SRL1") == 0)
            token = SRL1;
        else if (strcmp(UCLexeme, "SL1") == 0)
            token = SL1;
        else if (strcmp(UCLexeme, "FETCH") == 0)
            token = FETCH;
        else if (strcmp(UCLexeme, "READ") == 0)
            token = READ;
        else if (strcmp(UCLexeme, "WRITE") == 0)
            token = WRITE;
        else if (strcmp(UCLexeme, "H") == 0)
            token = H;
        else if (strcmp(UCLexeme, "OPC") == 0)
            token = OPC;
        else if (strcmp(UCLexeme, "T0") == 0)
            // alias of OPC
            token = OPC;
        else if (strcmp(UCLexeme, "TOS") == 0)
            token = TOS;
        else if (strcmp(UCLexeme, "CPP") == 0)
            token = CPP;
        else if (strcmp(UCLexeme, "LV") == 0)
            token = LV;
        else if (strcmp(UCLexeme, "SP") == 0)
            token = SP;
        else if (strcmp(UCLexeme, "PC") == 0)
            token = PC;
        else if (strcmp(UCLexeme, "MDR") == 0)
            token = MDR;
        else if (strcmp(UCLexeme, "MAR") == 0)
            token = MAR;
        else if (strcmp(UCLexeme, "MBR") == 0)
            token = MBR;
        else if (strcmp(UCLexeme, "MBRU") == 0)
            token = MBRU;
        else if (strcmp(UCLexeme, "T1") == 0)
            token = T1;
        else if (strcmp(UCLexeme, "T2") == 0)
            token = T2;
        else if (strcmp(UCLexeme, "T3") == 0)
            token = T3;
        else
            token = LABEL;
    }
    else
    {
        switch (nextCharacter)
        {
            // <bitString>
        case '"':
        {
            int i;

            i = 0;
            GetNextCharacter();
            while (nextCharacter != '"')
            {
                if ((nextCharacter == '0') || (nextCharacter == '1'))
                {
                    lexeme[i++] = nextCharacter;
                    GetNextCharacter();
                }
                else
                    ProcessAssemblerError((char*)"Illegal bitString");
            }
            lexeme[i] = '\0';
            if ((int)strlen(lexeme) != MICROINSTRUCTIONLENGTH)
                ProcessAssemblerError((char*)"Illegal bitString");
            GetNextCharacter();
            token = BITSTRING;
            break;
        }
        // <hexAddress>
        case '0':
        {
            int i;

            i = 0;
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
            if (toupper(nextCharacter) == 'X')
            {
                lexeme[i++] = toupper(nextCharacter);
                GetNextCharacter();
                if ((nextCharacter == '0') || (nextCharacter == '1'))
                {
                    lexeme[i++] = nextCharacter;
                    GetNextCharacter();
                    if (isxdigit(nextCharacter))
                    {
                        lexeme[i++] = nextCharacter;
                        GetNextCharacter();
                        if (isxdigit(nextCharacter))
                        {
                            lexeme[i++] = nextCharacter;
                            GetNextCharacter();
                            token = HEXADDRESS;
                        }
                        else
                            ProcessAssemblerError((char*)"Illegal hexAddress");
                    }
                    else
                        ProcessAssemblerError((char*)"Illegal hexAddress");
                }
                else
                    ProcessAssemblerError((char*)"Illegal hexAddress");
            }
            else
            {
                token = LITERAL0;
                GetNextCharacter();
            }
            lexeme[i] = '\0';
            break;
        }
        case '1':
            token = LITERAL1;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case '4':
            token = LITERAL4;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case '=':
            token = EQUALSSIGN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case '+':
            token = PLUSSIGN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case '-':
            token = MINUSSIGN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case EOLC:
            token = EOLTOKEN;
            break;
        case EOFC:
            token = EOFTOKEN;
            break;
        default:
            token = UNKNOWN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        }
    }
}

//----------------------------------------------------
void GetNextCharacter()
//----------------------------------------------------
{
    if (atEOF)
        nextCharacter = EOFC;
    else if (sourceLineIndex <= ((int)strlen(sourceLine) - 1))
    {
        nextCharacter = sourceLine[sourceLineIndex];
        sourceLineIndex += 1;
    }
    else
        nextCharacter = EOLC;
}

//----------------------------------------------------
void GetNextSourceLine()
//----------------------------------------------------
{
    if (fgets(sourceLine, LINELENGTH + 1, SOURCE) == NULL)
        atEOF = true;
    else
    {
        atEOF = false;
        // Erase control characters at end of source line (if any)
        while ((0 <= (int)strlen(sourceLine) - 1) &&
            iscntrl(sourceLine[strlen(sourceLine) - 1]))
            sourceLine[strlen(sourceLine) - 1] = '\0';
        sourceLineIndex = 0;
    }
}

//--------------------------------------------------
void ProcessAssemblerError(char errorMessage[])
//--------------------------------------------------
{
    /*
    Error Messages
    ==============
    Syntax errors
       Expecting EOL
       Control store capacity exceeded
       Multiply-defined label
       Multiply-defined hexAddress
       Undefined label
       Expecting nextAddress field
       Attempt to READ and WRITE memory at the same time
       Expecting B-Bus register
       Expecting C-Bus register
       Expecting TO or =
       Expecting H or 1
       Expecting 1
       Expecting hexAddress
       Expecting hexAddress or label
       Expecting Z, P, N, or NOT
       Expecting Z, P, or N
       Expecting THEN
       Expecting ELSE
       Expecting GOTO
       Expecting 0X100 <= JAM address
       JAM NEXT microinstruction address out-of-range
       JAM THEN microinstruction does not exist
       JAM THEN microinstruction address is unavailable
       JAM ELSE microinstruction address out-of-range
       JAM ELSE microinstruction does not exist
       JAM ELSE microinstruction address is unavailable
       JAM THEN microinstruction address != ELSE microinstruction address+0X100
       JAM THEN/ELSE microinstruction address pair is unavailable
       Illegal hexAddress
       Illegal bitString

      Use panic mode error recovery technique; namely, report error message,
          close files and terminate compilation
    */

    fprintf(LOG, "                                                           ");
    fprintf(LOG, "%4d  %s\n", sourceLineNumber, sourceLine);
    fprintf(LOG, "                                                           ");
    fprintf(LOG, "       ");
    for (int i = 1; i <= (sourceLineIndex - 1); i++)
        fprintf(LOG, " ");
    fprintf(LOG, "^ %s\n", errorMessage); fflush(LOG);
    fclose(SOURCE);
    fclose(LOG);

    printf("Source contains an error, Mic1 control store not created\n");
    system("PAUSE");
    exit(1);
}
