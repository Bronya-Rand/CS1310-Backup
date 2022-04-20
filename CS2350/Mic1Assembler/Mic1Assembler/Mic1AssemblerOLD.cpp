//----------------------------------------------------
// Dr. Art Hanna
// Mic1 Assembler
//    8/15/2017 1.0 
//    4/24/2018 1.1 added aliases for conditional JMPs
//                  added JMPT, JMPF to ISA
//    3/11/2020 1.2 changed "LineIsLabeled" typo found in DoPass2() 
//                  to "lineIsLabeled" (found by Joel Trejo (Spring, 2020))
//    4/15/2021 1.2 added SL1 for Exam over Chapter #7
//                  
// Mic1Assembler.cpp
//----------------------------------------------------
#define MIC1_VERSION "1.2 3/11/2020"

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

typedef unsigned char BYTE;
typedef int           WORD32;

#define LINELENGTH               255
#define LINESPERPAGE              55
#define EOFCHARACTER             (1)
#define EOLCHARACTER             (2)

const WORD32 MINMEMORYADDRESS = 0X00000000;  // minimum usable memory address
const WORD32 MAXMEMORYADDRESS = 0X000FFFFF;  // maximum usable memory address

#define RECORDSYNTAXERROR(syntaxError)                       \
{                                                            \
   if ( numberOfSyntaxErrors <= 4 )                          \
      syntaxErrors[++numberOfSyntaxErrors] = syntaxError;    \
}

#define BYTE1(word) ((0XFF000000 & word) >> 24)
#define BYTE2(word) ((0X00FF0000 & word) >> 16)
#define BYTE3(word) ((0X0000FF00 & word) >>  8)
#define BYTE4(word) ( 0X000000FF & word)

//========================================
enum TOKEN
    //========================================
{
    // assembler mnemonics
    ORG,
    RW,
    DW,
    DS,
    // registers
    LV,
    SP,
    CPP,
    // hardware mnemonics
    NOOP,
    PUSH,
    PUSHA,
    POP,
    DISCARD,
    SWAP,
    MAKEDUP,
    PUSHLV,
    POPLV,
    PUSHSP,
    POPSP,
    PUSHCPP,
    POPCPP,
    ADD,
    SUB,
    NEG,
    AND,
    OR,
    NOT,
    CMP,
    CMPU,
    SRA1,
    SL1,
    JMP, //aliases for conditional JMPs
    JMPL, JMPN,
    JMPE, JMPZ,
    JMPG, JMPP,
    JMPLE, JMPNP,
    JMPGE, JMPNN,
    JMPNE, JMPNZ,
    JMPT,
    JMPF,
    CALL,
    RETURN,
    SVC,
    // punctuation characters
    ATSIGN,
    POUNDSIGN,
    COLON,
    // pseudo-terminals
    IDENTIFIER,
    INTEGER,
    STRING,
    EOFTOKEN,
    EOLTOKEN,
    UNKNOWN
};

//========================================
enum SYNTAXERROR
    //========================================
{
    ORG_MAY_NOT_BE_LABELED,
    MNEMONIC_MISSING,
    UNRECOGNIZABLE_INSTRUCTION,
    INVALID_RW_OPERAND,
    INVALID_DW_OPERAND,
    INVALID_DS_OPERAND,
    MULTIPLY_DEFINED_IDENTIFIER,
    UNDEFINED_IDENTIFIER,
    INTEGER_MISSING,
    INTEGER_OR_IDENTIFIER_MISSING,
    POUNDSIGN_MISSING,
    COLON_MISSING,
    IMMEDIATE_MODE_NOT_ALLOWED,
    EOL_EXPECTED,
    LOCATION_COUNTER_OVERFLOW
};

//========================================
const char syntaxErrorMessages[][50 + 1] =
//========================================
{
    //  12345678901234567890123456789012345678901234567890
       "ORG may not be labeled",
       "Labeled line must contain a mnemonic",
       "Unrecognizable instruction",
       "Invalid RW operand",
       "Invalid DW operand",
       "Invalid DS operand",
       "Multiply defined identifier",
       "Undefined identifier",
       "Integer is missing",
       "Integer or identifier is missing",
       "'#' missing",
       "':' missing",
       "Immediate mode not allowed for PUSHA or POP",
       "End of source line expected",
       "Location counter overflow"
};

enum OPERANDTYPE
{
    NONE,
    MEMORY,
    DIRO32,
    IMMO32
    //------------------------------------------------------------
    // Add new ISA machine instruction operands field formats...
    //------------------------------------------------------------
};

//========================================
struct HWOPERATIONRECORD
    //========================================
{
    int opCode;
    int sizeInBytes;
    char mnemonic[8 + 1];    // *CUIDADO* increase size for longer-than-8-character mnemonics
    TOKEN token;
    OPERANDTYPE operandType;
};

//========================================
const HWOPERATIONRECORD HWOperationTable[] =
//========================================
{
   { 0X00,1,"NOOP"    ,NOOP    ,NONE   },
   { 0X01,6,"PUSH"    ,PUSH    ,MEMORY },
   { 0X02,6,"PUSHA"   ,PUSHA   ,MEMORY },
   { 0X03,6,"POP"     ,POP     ,MEMORY },
   { 0X04,5,"DISCARD" ,DISCARD ,IMMO32 },
   { 0X05,1,"SWAP"    ,SWAP    ,NONE   },
   { 0X06,1,"MAKEDUP" ,MAKEDUP ,NONE   },
   { 0X07,1,"PUSHLV"  ,PUSHLV  ,NONE   },
   { 0X08,1,"POPLV"   ,POPLV   ,NONE   },
   { 0X09,1,"PUSHSP"  ,PUSHSP  ,NONE   },
   { 0X0A,1,"POPSP"   ,POPSP   ,NONE   },
   { 0X0B,1,"PUSHCPP" ,PUSHCPP ,NONE   },
   { 0X0C,1,"POPCPP"  ,POPCPP  ,NONE   },
   { 0X10,1,"ADD"     ,ADD     ,NONE   },
   { 0X11,1,"SUB"     ,SUB     ,NONE   },
   { 0X12,1,"NEG"     ,NEG     ,NONE   },
   { 0X13,1,"AND"     ,AND     ,NONE   },
   { 0X14,1,"OR"      ,OR      ,NONE   },
   { 0X15,1,"NOT"     ,NOT     ,NONE   },
   { 0X16,1,"CMP"     ,CMP     ,NONE   },
   { 0X17,1,"CMPU"    ,CMPU    ,NONE   },
   { 0X18,1,"SRA1"    ,SRA1    ,NONE   },
   { 0X19,1,"SL1"     ,SL1     ,NONE   },
   { 0X30,5,"JMP"     ,JMP     ,DIRO32 },
   { 0X31,5,"JMPL"    ,JMPL    ,DIRO32 },
   { 0X31,5,"JMPN"    ,JMPL    ,DIRO32 }, //alias for JMPL
   { 0X32,5,"JMPE"    ,JMPE    ,DIRO32 },
   { 0X32,5,"JMPZ"    ,JMPE    ,DIRO32 }, //alias for JMPE
   { 0X33,5,"JMPG"    ,JMPG    ,DIRO32 },
   { 0X33,5,"JMPP"    ,JMPG    ,DIRO32 }, //alias for JMPG
   { 0X34,5,"JMPLE"   ,JMPLE   ,DIRO32 },
   { 0X34,5,"JMPNP"   ,JMPLE   ,DIRO32 }, //alias for JMPLE
   { 0X35,5,"JMPGE"   ,JMPGE   ,DIRO32 },
   { 0X35,5,"JMPNN"   ,JMPGE   ,DIRO32 }, //alias for JMPGE
   { 0X36,5,"JMPNE"   ,JMPNE   ,DIRO32 },
   { 0X36,5,"JMPNZ"   ,JMPNE   ,DIRO32 }, //alias for JMPNE
   { 0X37,5,"JMPT"    ,JMPT    ,DIRO32 },
   { 0X38,5,"JMPF"    ,JMPF    ,DIRO32 },
   { 0X3D,5,"CALL"    ,CALL    ,DIRO32 },
   { 0X3E,1,"RETURN"  ,RETURN  ,NONE   },
   { 0X3F,5,"SVC"     ,SVC     ,IMMO32 }
};

//====================================================
template <int SIZEOFTABLE, int MAXIMUMLENGTHIDENTIFIER>
struct IDENTIFIERTABLE
    //====================================================
{
public:
    int size;
    WORD32 addresses[SIZEOFTABLE + 1];
    bool isHWInstructionLabel[SIZEOFTABLE + 1];
    char identifiers[SIZEOFTABLE + 1][MAXIMUMLENGTHIDENTIFIER + 1];

    //----------------------------------------------------
    IDENTIFIERTABLE()
        //----------------------------------------------------
    {
        size = 0;
    }

    //----------------------------------------------------
    void AddToTable(char lexeme[], WORD32 address, bool isHWInstructionLabel)
        //----------------------------------------------------
    {
        void DisplayScreenMessage(char runTimeMessage[], bool abort);

        if (size <= SIZEOFTABLE)
        {
            size++;
            addresses[size] = address;
            this->isHWInstructionLabel[size] = isHWInstructionLabel;
            strncpy(identifiers[size], lexeme, MAXIMUMLENGTHIDENTIFIER);
        }
        else
            DisplayScreenMessage((char*)"Identifier table overflow\n", true);
    }

    //----------------------------------------------------
    bool IsInTable(char lexeme[])
        //----------------------------------------------------
    {
        bool inTable;
        char uLexeme[LINELENGTH + 1];
        int index;

        for (int i = 0; i <= (int)strlen(lexeme); i++)
            uLexeme[i] = toupper(lexeme[i]);
        inTable = false;
        index = 1;
        while (!inTable && (index <= size))
        {
            char uIdentifier[MAXIMUMLENGTHIDENTIFIER];

            for (int i = 0; i <= (int)strlen(identifiers[index]); i++)
                uIdentifier[i] = toupper(identifiers[index][i]);
            if (strncmp(uIdentifier, uLexeme, MAXIMUMLENGTHIDENTIFIER) == 0)
                inTable = true;
            else
                index++;
        }
        return(inTable);
    }

    //----------------------------------------------------
    int IndexInTable(char lexeme[])
        //----------------------------------------------------
    {
        void DisplayScreenMessage(char runTimeMessage[], bool abort);

        bool inTable;
        char uLexeme[LINELENGTH + 1];
        int index;

        for (int i = 0; i <= (int)strlen(lexeme); i++)
            uLexeme[i] = toupper(lexeme[i]);
        inTable = false;
        index = 1;
        while (!inTable && (index <= size))
        {
            char uIdentifier[MAXIMUMLENGTHIDENTIFIER];

            for (int i = 0; i <= (int)strlen(identifiers[index]); i++)
                uIdentifier[i] = toupper(identifiers[index][i]);
            if (strncmp(uIdentifier, uLexeme, MAXIMUMLENGTHIDENTIFIER) == 0)
                inTable = true;
            else
                index++;
        }

        if (!inTable)
        {
            char message[80 + 1];

            sprintf(message, "\"%s\" not found in table\n", lexeme);
            DisplayScreenMessage(message, true);
        }
        return(index);
    }

    //----------------------------------------------------
    int IndexInTable(WORD32 address)
        //----------------------------------------------------
    {
        void DisplayScreenMessage(char runTimeMessage[], bool abort);

        bool inTable;
        int index;

        inTable = false;
        index = 1;
        while (!inTable && (index <= size))
        {
            if (addresses[index] == address)
                inTable = true;
            else
                index++;
        }

        if (!inTable)
        {
            char message[80 + 1];

            sprintf(message, "Identifer at 0X%08X not found in table\n", address);
            DisplayScreenMessage(message, true);
        }

        return(index);
    }

    //----------------------------------------------------
    bool IsInTable(WORD32 address)
        //----------------------------------------------------
    {
        bool inTable;
        int index;

        inTable = false;
        index = 1;
        while (!inTable && (index <= size))
        {
            if (addresses[index] == address)
                inTable = true;
            else
                index++;
        }
        return(inTable);
    }
};

//=============================================================
// GLOBAL VARIABLES (OMG!!!)
//=============================================================
FILE* SOURCE, * LISTING, * OBJECT;
char sourceLine[LINELENGTH + 1], nextCharacter, title[LINELENGTH + 1];
int sourceLineIndex, numberOfSyntaxErrors, syntaxErrors[4 + 1];
bool atEOF;

IDENTIFIERTABLE<500, 128> identifierTable;

BYTE mainMemory[MAXMEMORYADDRESS + 1];
bool dirtyByte[MAXMEMORYADDRESS + 1];

//*************************************************************
int main()
//*************************************************************
{
    void DoPass1();
    void DoPass2();
    void InitializeMainMemory();
    void BuildObjectFile();

    char sourceFilename[LINELENGTH + 1], fullFilename[LINELENGTH + 1];

    cout << "Mic-1 version " << MIC1_VERSION << "\n\n";

    cout << "Source filename? "; cin >> sourceFilename;
    strcpy(fullFilename, sourceFilename);
    strcat(fullFilename, ".mic1");
    if ((SOURCE = fopen(fullFilename, "r")) == NULL)
    {
        cout << "Error opening source file " << fullFilename << endl;
        system("PAUSE");
        exit(1);
    }

    strcpy(title, fullFilename);
    strcpy(fullFilename, sourceFilename);
    strcat(fullFilename, ".listing");
    if ((LISTING = fopen(fullFilename, "w")) == NULL)
    {
        cout << "Error opening listing file " << fullFilename << endl;
        system("PAUSE");
        exit(1);
    }

    cout << "Listing file is " << fullFilename << endl;
    strcpy(fullFilename, sourceFilename);
    strcat(fullFilename, ".object");
    if ((OBJECT = fopen(fullFilename, "w")) == NULL)
    {
        cout << "Error opening object file " << fullFilename << endl;
        system("PAUSE");
        exit(1);
    }

    cout << "Object  file is " << fullFilename << endl;

    InitializeMainMemory();
    DoPass1();
    rewind(SOURCE);
    DoPass2();
    BuildObjectFile();

    fclose(SOURCE);
    fclose(LISTING);
    fclose(OBJECT);

    system("PAUSE");
    return(0);
}

//----------------------------------------------------
void DoPass1()
//----------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    WORD32 ATOI(char string[]);

    TOKEN token;
    char lexeme[LINELENGTH + 1];
    WORD32 LC;

    LC = 0X00000000;

    // Each statement is wholly contained on 1 source line
    GetNextSourceLine();
    while (!atEOF)
    {
        GetNextCharacter();
        /*
              Is first token an identifier? If so, it is a statement label; add the
                 lexeme, its value, and whether it labels a HW instruction (or not)
                 to the identifier table when the label is not already there.
        */
        GetNextToken(token, lexeme);
        if (token == IDENTIFIER)
        {
            char label[LINELENGTH + 1];
            bool isHWInstructionLabel;

            strcpy(label, lexeme);
            GetNextToken(token, lexeme);
            isHWInstructionLabel = !((token == ORG) || (token == RW) || (token == DW) || (token == DS));
            if (!identifierTable.IsInTable(label))
                identifierTable.AddToTable(label, LC, isHWInstructionLabel);
        }
        if (token == ORG)
        {
            GetNextToken(token, lexeme);
            if (token == INTEGER)
                LC = ATOI(lexeme);
            else
                LC = 0X00000000;
        }
        else if (token == RW)
        {
            GetNextToken(token, lexeme);
            if (token == INTEGER)
                LC += 4 * ATOI(lexeme);
            else
                LC += 4;
        }
        else if (token == DW)
        {
            LC += 4;
        }
        else if (token == DS)
        {
            // Insert a NUL character at end of string
            GetNextToken(token, lexeme);
            if (token == STRING)
                LC += (int)strlen(lexeme) + 1;
            else
                LC += 1;
        }
        else if ((NOOP <= token) && (token <= SVC))
        {
            int i = 0;

            while (token != HWOperationTable[i].token)
                i++;
            LC += HWOperationTable[i].sizeInBytes;
        }
        else
        {
            ; // Illegal token which will be diagnosed during pass #2
        }
        GetNextSourceLine();
    }
}

//----------------------------------------------------
void DoPass2()
//----------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    void GetNextCharacter();
    void GetNextSourceLine();
    void ParseO32(TOKEN & token, char lexeme[], WORD32 & O32);
    void PrintTopOfPageHeader(int& pageNumber, int& lines);
    WORD32 ATOI(char string[]);
    void WriteMainMemoryByte(WORD32 address, BYTE byte);

    TOKEN token;
    char lexeme[LINELENGTH + 1];
    BYTE objectCode[256 + 1];
    int objectBytes;
    WORD32 O32, oldLC, LC;
    int i, lineNumber, lines, pageNumber, mode;
    bool lineIsLabeled, lineContainsMnemonic;

    LC = 0X00000000;
    lineNumber = 0;
    pageNumber = 0;
    lines = 0;
    PrintTopOfPageHeader(pageNumber, lines);

    // Each statement is wholly contained on 1 source line
    GetNextSourceLine(); lineNumber++;
    while (!atEOF)
    {
        oldLC = LC;
        numberOfSyntaxErrors = 0;
        GetNextCharacter();
        GetNextToken(token, lexeme);
        lineContainsMnemonic = false;

        // Is first token an identifier? If so, is it multiply defined?
        if (token == IDENTIFIER)
        {
            if (identifierTable.addresses[identifierTable.IndexInTable(lexeme)] != LC)
                RECORDSYNTAXERROR(MULTIPLY_DEFINED_IDENTIFIER);
            GetNextToken(token, lexeme);
            lineIsLabeled = true;
        }
        else
        {
            lineIsLabeled = false;
        }
        // Is line a blank line or a comment-only line?
        if (token == EOLTOKEN)
        {
            if (lineIsLabeled) RECORDSYNTAXERROR(MNEMONIC_MISSING);
            objectBytes = 0;
        }
        else      if (token == ORG)
        {
            if (lineIsLabeled) RECORDSYNTAXERROR(ORG_MAY_NOT_BE_LABELED);
            //BUGFIX "LineIsLabeled" typo changed to "lineIsLabeled"
            // bug discovered by Joel Trejo (Spring, 2020)
            objectBytes = 0;
            GetNextToken(token, lexeme);
            if (token == INTEGER)
                LC = ATOI(lexeme);
            else
            {
                RECORDSYNTAXERROR(INTEGER_MISSING);
                LC = 0X0000000;
            }
        }
        else if (token == RW)
        {
            GetNextToken(token, lexeme);
            objectBytes = 0;
            if (token == INTEGER)
                LC += 4 * ATOI(lexeme);
            else if (token == EOLTOKEN)
                LC += 4;
            else
            {
                RECORDSYNTAXERROR(INVALID_RW_OPERAND);
                LC += 4;
            }
        }
        else if (token == DW)
        {
            objectBytes = 4;
            GetNextToken(token, lexeme);
            if (token == INTEGER)
                O32 = ATOI(lexeme);
            else if (token == IDENTIFIER)
            {
                if (identifierTable.IsInTable(lexeme))
                    O32 = identifierTable.addresses[identifierTable.IndexInTable(lexeme)];
                else
                {
                    RECORDSYNTAXERROR(UNDEFINED_IDENTIFIER);
                    O32 = 0X00000000;
                }
            }
            else
            {
                RECORDSYNTAXERROR(INVALID_DW_OPERAND);
                O32 = 0X00000000;
            }
            objectCode[1] = BYTE1(O32);
            objectCode[2] = BYTE2(O32);
            objectCode[3] = BYTE3(O32);
            objectCode[4] = BYTE4(O32);
        }
        else if (token == DS)
        {
            GetNextToken(token, lexeme);
            if (token == STRING)
            {
                objectBytes = (int)strlen(lexeme);
                for (int i = 1; i <= objectBytes; i++)
                    objectCode[i] = (int)lexeme[i - 1];
                objectCode[++objectBytes] = 0X00;
            }
            else
            {
                objectBytes = 1;
                RECORDSYNTAXERROR(INVALID_DS_OPERAND);
                objectCode[1] = 0X00;
            }
        }
        else if ((NOOP <= token) && (token <= SVC))
        {
            int opCodeIndex;

            opCodeIndex = 0;
            while (token != HWOperationTable[opCodeIndex].token)
                opCodeIndex++;

            objectCode[1] = HWOperationTable[opCodeIndex].opCode;
            switch (HWOperationTable[opCodeIndex].operandType)
            {
            case   NONE:
                GetNextToken(token, lexeme);
                objectBytes = 1;
                break;
            case MEMORY:
                GetNextToken(token, lexeme);
                if (token == POUNDSIGN)
                {
                    if ((HWOperationTable[opCodeIndex].token == PUSHA) ||
                        (HWOperationTable[opCodeIndex].token == POP))
                        RECORDSYNTAXERROR(IMMEDIATE_MODE_NOT_ALLOWED);
                    mode = 0X00;
                    GetNextToken(token, lexeme);
                    ParseO32(token, lexeme, O32);
                    GetNextToken(token, lexeme);
                }
                else if (token == ATSIGN)
                {
                    GetNextToken(token, lexeme);
                    if (token == SP)
                    {
                        mode = 0X06;
                        GetNextToken(token, lexeme);
                        if (token != COLON)
                            RECORDSYNTAXERROR(COLON_MISSING);
                        GetNextToken(token, lexeme);
                        ParseO32(token, lexeme, O32);
                        GetNextToken(token, lexeme);
                    }
                    else if (token == LV)
                    {
                        mode = 0X0A;
                        GetNextToken(token, lexeme);
                        if (token != COLON)
                            RECORDSYNTAXERROR(COLON_MISSING);
                        GetNextToken(token, lexeme);
                        ParseO32(token, lexeme, O32);
                        GetNextToken(token, lexeme);
                    }
                    else if (token == CPP)
                    {
                        mode = 0X0E;
                        GetNextToken(token, lexeme);
                        if (token != COLON)
                            RECORDSYNTAXERROR(COLON_MISSING);
                        GetNextToken(token, lexeme);
                        ParseO32(token, lexeme, O32);
                        GetNextToken(token, lexeme);
                    }
                    else
                    {
                        mode = 0X02;
                        ParseO32(token, lexeme, O32);
                        GetNextToken(token, lexeme);
                    }
                }
                else if (token == SP)
                {
                    mode = 0X05;
                    GetNextToken(token, lexeme);
                    if (token != COLON)
                        RECORDSYNTAXERROR(COLON_MISSING);
                    GetNextToken(token, lexeme);
                    ParseO32(token, lexeme, O32);
                    GetNextToken(token, lexeme);
                }
                else if (token == LV)
                {
                    mode = 0X09;
                    GetNextToken(token, lexeme);
                    if (token != COLON)
                        RECORDSYNTAXERROR(COLON_MISSING);
                    GetNextToken(token, lexeme);
                    ParseO32(token, lexeme, O32);
                    GetNextToken(token, lexeme);
                }
                else if (token == CPP)
                {
                    mode = 0X0D;
                    GetNextToken(token, lexeme);
                    if (token != COLON)
                        RECORDSYNTAXERROR(COLON_MISSING);
                    GetNextToken(token, lexeme);
                    ParseO32(token, lexeme, O32);
                    GetNextToken(token, lexeme);
                }
                else
                {
                    mode = 0X01;
                    ParseO32(token, lexeme, O32);
                    GetNextToken(token, lexeme);
                }
                objectCode[2] = BYTE1(O32);
                objectCode[3] = BYTE2(O32);
                objectCode[4] = BYTE3(O32);
                objectCode[5] = BYTE4(O32);
                objectCode[6] = mode;
                objectBytes = 6;
                break;
            case DIRO32:
                GetNextToken(token, lexeme);
                ParseO32(token, lexeme, O32);
                objectCode[2] = BYTE1(O32);
                objectCode[3] = BYTE2(O32);
                objectCode[4] = BYTE3(O32);
                objectCode[5] = BYTE4(O32);
                objectBytes = 5;
                break;
            case IMMO32:
                GetNextToken(token, lexeme);
                if (token != POUNDSIGN)
                {
                    RECORDSYNTAXERROR(POUNDSIGN_MISSING);
                    O32 = 0X00000000;
                }
                else
                {
                    GetNextToken(token, lexeme);
                    ParseO32(token, lexeme, O32);
                }
                objectCode[2] = BYTE1(O32);
                objectCode[3] = BYTE2(O32);
                objectCode[4] = BYTE3(O32);
                objectCode[5] = BYTE4(O32);
                objectBytes = 5;
                break;
            }
        }
        else
        {
            objectBytes = 0;
            RECORDSYNTAXERROR(UNRECOGNIZABLE_INSTRUCTION);
        }
        GetNextToken(token, lexeme);
        if (token != EOLTOKEN)
            RECORDSYNTAXERROR(EOL_EXPECTED);
        /*
                LC  Object        Line  Source Line
        ----------  ------------  ----  -----------------------------------------------------------------------  ----------  ------  -------------------------------------------------------------
        0XXXXXXXXX  XXXXXXXXXXXX  XXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
           ***Error (XXXX) XXX...XXX
        */
        if (lines > LINESPERPAGE)
            PrintTopOfPageHeader(pageNumber, lines);
        fprintf(LISTING, "0X%08X  ", oldLC);
        for (int j = 1; j <= 6; j++)
        {
            if (j <= objectBytes)
                fprintf(LISTING, "%02X", objectCode[j]);
            else
                fprintf(LISTING, "  ");
        }
        fprintf(LISTING, "  %4d  %s\n", lineNumber, sourceLine); fflush(LISTING);
        lines++;
        i = 7;
        while (i <= objectBytes)
        {
            if (lines > LINESPERPAGE)
                PrintTopOfPageHeader(pageNumber, lines);
            fprintf(LISTING, "0X%08X  ", (oldLC + i - 1));
            for (int j = 1; j <= 6; j++)
            {
                if (j + i - 1 <= objectBytes)
                    fprintf(LISTING, "%02X", objectCode[j + i - 1]);
                else
                    fprintf(LISTING, "  ");
            }
            fprintf(LISTING, "\n"); fflush(LISTING);
            lines++;
            i = i + 6;
        }
        LC = LC + objectBytes;
        if ((LC - 1) > MAXMEMORYADDRESS)
        {
            RECORDSYNTAXERROR(LOCATION_COUNTER_OVERFLOW);
            LC = 0X00000000;
        }
        for (i = 1; i <= numberOfSyntaxErrors; i++)
        {
            if (lines > LINESPERPAGE)
                PrintTopOfPageHeader(pageNumber, lines);
            fprintf(LISTING, "   ***Error (%4d) %s\n", syntaxErrors[i],
                syntaxErrorMessages[syntaxErrors[i]]); fflush(LISTING);
            lines++;
            cout << "***Error (" << setw(4) << syntaxErrors[i] << ") "
                << syntaxErrorMessages[syntaxErrors[i]] << endl;
        }
        for (i = 1; i <= objectBytes; i++)
            WriteMainMemoryByte((WORD32)(oldLC + i - 1), objectCode[i]);
        GetNextSourceLine(); lineNumber++;
    }
}

//----------------------------------------------------
void BuildObjectFile()
//----------------------------------------------------
{
    bool MainMemoryByteIsDirty(int address);
    void ReadMainMemoryByte(WORD32 address, BYTE & byte);

    int bytes;

    /*
       Output identifierTable used by Mic1 simulation to disassemble ISA instructions

    record 1: DDD
           2: 0XHHHHHHHH *AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
           3: 0XHHHHHHHH  AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
           .       . .
           .       . .
      size+1: 0XHHHHHHHH *AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    */
    fprintf(OBJECT, "%3d\n", identifierTable.size);
    for (int i = 1; i <= identifierTable.size; i++)
    {
        fprintf(OBJECT, "0X%08X %c%s\n", identifierTable.addresses[i],
            ((identifierTable.isHWInstructionLabel[i]) ? '*' : ' '),
            identifierTable.identifiers[i]);
    }
    /*
       Output binary object code in hexadecimal using the following format

    0XHHHHHHHH: is the hexadecimal main memory address of the first of 1 or more 2-nibble bytes

    0X00000000: HH HH HH ... HH
         .
         .
    0XHHHHHHHH: HH HH HH ... HH
    */
    bytes = 0;
    for (WORD32 address = 0X00000000; address <= MAXMEMORYADDRESS; address++)
    {
        if (MainMemoryByteIsDirty(address))
        {
            BYTE byte;

            ReadMainMemoryByte(address, byte);
            if (bytes == 0)
                fprintf(OBJECT, "0X%08X:", address);
            fprintf(OBJECT, " %02X", byte);
            bytes++;
            if (bytes == 16)
            {
                fprintf(OBJECT, "\n");
                bytes = 0;
            }
        }
        else if (bytes > 0)
        {
            fprintf(OBJECT, "\n");
            bytes = 0;
        }
    }
    if (bytes > 0)
        fprintf(OBJECT, "\n");
}

//----------------------------------------------------
void ParseO32(TOKEN& token, char lexeme[], WORD32& O32)
//----------------------------------------------------
{
    void GetNextToken(TOKEN & token, char lexeme[]);
    WORD32 ATOI(char string[]);

    if (token == IDENTIFIER)
    {
        if (identifierTable.IsInTable(lexeme))
            O32 = identifierTable.addresses[identifierTable.IndexInTable(lexeme)];
        else
        {
            RECORDSYNTAXERROR(UNDEFINED_IDENTIFIER);
            O32 = 0X00000000;
        }
        GetNextToken(token, lexeme);
    }
    else if (token == INTEGER)
    {
        O32 = ATOI(lexeme);
        GetNextToken(token, lexeme);
    }
    else
    {
        O32 = 0X00000000;
        RECORDSYNTAXERROR(INTEGER_OR_IDENTIFIER_MISSING);
    }
}

//----------------------------------------------------
WORD32 ATOI(char string[])
//----------------------------------------------------
{
    WORD32 r;

    if ((strchr(string, 'x') != NULL) || (strchr(string, 'X') != NULL))
        sscanf(string, "%X", &r);
    else
        sscanf(string, "%d", &r);
    return(r);
}

//----------------------------------------------------
void PrintTopOfPageHeader(int& pageNumber, int& lines)
//----------------------------------------------------
{
    const char FF = 0X0C;
    /*
             11111111112222222222333333333344444444445555555555666666666677777777778
    12345678901234567890123456789012345678901234567890123456789012345678901234567890
    Page XXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

            LC  Object        Line  Source Line
    ----------  ------------  ----  -------------------------------------------------------------
    0XXXXXXXXX  XXXXXXXXXXXX  XXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    */
    pageNumber++;
    lines = 0;
    fprintf(LISTING, "%cPage %3d  %s\n\n", FF, pageNumber, title);
    fprintf(LISTING, "        LC  Object        Line  Source Line\n");
    fprintf(LISTING, "----------  ------------  ----  -------------------------------------------------------------\n"); fflush(LISTING);
}

//----------------------------------------------------
void GetNextToken(TOKEN& token, char lexeme[])
//----------------------------------------------------
{
    void GetNextCharacter();

    int i;
    char UCLexeme[LINELENGTH + 1];

    // "Eat" blanks and tabs (if any)
    while ((nextCharacter == ' ') || (nextCharacter == '\t'))
        GetNextCharacter();

    // "Eat" comments (if any) *Note* comments are *ALWAYS* assumed to extend to EOL
    if (nextCharacter == ';')
        do
            GetNextCharacter();
    while (nextCharacter != EOLCHARACTER);

    // Assembler mnemonics, registers, identifiers, and hardware mnemonics
    if (isalpha(nextCharacter))
    {
        i = 0;
        lexeme[i++] = nextCharacter;
        GetNextCharacter();
        while (isalpha(nextCharacter) ||
            isdigit(nextCharacter) ||
            (nextCharacter == '_') ||
            (nextCharacter == '.'))
        {
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
        }
        lexeme[i] = '\0';
        for (i = 0; i <= (int)strlen(lexeme); i++)
            UCLexeme[i] = toupper(lexeme[i]);
        if (strcmp(UCLexeme, "ORG") == 0)
            token = ORG;
        else if (strcmp(UCLexeme, "RW") == 0)
            token = RW;
        else if (strcmp(UCLexeme, "DW") == 0)
            token = DW;
        else if (strcmp(UCLexeme, "DS") == 0)
            token = DS;
        else if (strcmp(UCLexeme, "SP") == 0)
            token = SP;
        else if (strcmp(UCLexeme, "LV") == 0)
            token = LV;
        else if (strcmp(UCLexeme, "CPP") == 0)
            token = CPP;
        else
        {
            token = IDENTIFIER;
            for (i = 0; i <= (sizeof(HWOperationTable) / sizeof(HWOPERATIONRECORD)) - 1; i++)
                if (strcmp(UCLexeme, HWOperationTable[i].mnemonic) == 0)
                    token = HWOperationTable[i].token;
        }
    }
    else if (isdigit(nextCharacter)
        || (nextCharacter == '+')
        || (nextCharacter == '-'))
    {
        bool hexDigitsAllowed;

        i = 0;
        if ((nextCharacter == '+')
            || (nextCharacter == '-'))
        {
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
        }
        if (nextCharacter == '0')
        {
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
            if (toupper(nextCharacter) == 'X')
                hexDigitsAllowed = true;
            else
                hexDigitsAllowed = false;
        }
        else
            hexDigitsAllowed = false;
        lexeme[i++] = nextCharacter;
        GetNextCharacter();
        while (hexDigitsAllowed ? isxdigit(nextCharacter) : isdigit(nextCharacter))
        {
            lexeme[i++] = nextCharacter;
            GetNextCharacter();
        }
        token = INTEGER;
        lexeme[i] = '\0';
    }
    else
    {
        switch (nextCharacter)
        {
        case '"':
            token = STRING;
            i = 0;
            GetNextCharacter();
            while ((nextCharacter != '"') && (nextCharacter != EOLCHARACTER))
            {
                if (nextCharacter == '\\')
                    GetNextCharacter();
                lexeme[i++] = nextCharacter;
                GetNextCharacter();
            }
            lexeme[i] = '\0';
            GetNextCharacter();
            break;
        case '@':
            token = ATSIGN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case '#':
            token = POUNDSIGN;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case ':':
            token = COLON;
            lexeme[0] = nextCharacter; lexeme[1] = '\0';
            GetNextCharacter();
            break;
        case EOLCHARACTER:
            token = EOLTOKEN;
            lexeme[0] = '\0';
            break;
        case EOFCHARACTER:
            token = EOFTOKEN;
            lexeme[0] = '\0';
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
        nextCharacter = EOFCHARACTER;
    else if (sourceLineIndex <= ((int)strlen(sourceLine) - 1))
    {
        nextCharacter = sourceLine[sourceLineIndex];
        sourceLineIndex += 1;
    }
    else
        nextCharacter = EOLCHARACTER;
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

//----------------------------------------------------
void InitializeMainMemory()
//----------------------------------------------------
{
    for (WORD32 address = 0X00000000; address <= MAXMEMORYADDRESS - 1; address++)
        dirtyByte[address] = false;
}

//----------------------------------------------------
void WriteMainMemoryByte(WORD32 address, BYTE byte)
//----------------------------------------------------
{
    void DisplayScreenMessage(char runTimeMessage[], bool abort);

    if ((MINMEMORYADDRESS <= address) && (address <= MAXMEMORYADDRESS))
    {
        mainMemory[address] = byte;
        dirtyByte[address] = true;
    }
    else
    {
        char message[80 + 1];

        sprintf(message, "Illegal memory write attempt! location 0X%08X, byte 0X%02X", address, byte);
        DisplayScreenMessage(message, false);
    }
}

//----------------------------------------------------
void ReadMainMemoryByte(WORD32 address, BYTE& byte)
//----------------------------------------------------
{
    void DisplayScreenMessage(char runTimeMessage[], bool abort);

    if ((MINMEMORYADDRESS <= address) && (address <= MAXMEMORYADDRESS))
        byte = mainMemory[address];
    else
    {
        char message[80 + 1];

        sprintf(message, "Illegal memory read attempt! location 0X%08X", address);
        DisplayScreenMessage(message, false);
    }
}

//----------------------------------------------------
bool MainMemoryByteIsDirty(int address)
//----------------------------------------------------
{
    return(dirtyByte[address]);
}

//--------------------------------------------------
void DisplayScreenMessage(char runTimeMessage[], bool abort)
//--------------------------------------------------
{
    cout << runTimeMessage << (abort ? "...aborting" : "") << endl;
    if (abort)
    {
        system("PAUSE");
        exit(0);
    }
}

