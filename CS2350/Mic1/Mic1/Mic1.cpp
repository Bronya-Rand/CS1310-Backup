//----------------------------------------------------
// Dr. Art Hanna
// Mic1
//    8/15/2017 1.0 
//    4/24/2018 1.1 added aliases for conditional JMPs
//                  added JMPT, JMPF to ISA
//    3/11/2020 1.2 corrected for "deprecated conversion from string constant" warnings
//    4/19/2022 1.3 added support to run multiple simulation .listing files via input
//                  and use try/catch using invalid_argurment exceptions
//                  (by Azariel Del Carmen)
// Mic1.cpp
//----------------------------------------------------
#define MIC1_VERSION "1.3 4/19/2022"

#include <iostream>
#include <iomanip>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

typedef char BIT;
typedef unsigned char BYTE;
typedef int           WORD32;

#define LINELENGTH                     255
#define MININT                  0X80000000   // minimum 2's complement integer
#define MAXINT                  0X7FFFFFFF   // maximum 2's complement integer
#define MAXINTU                 0XFFFFFFFF   // maximum unsigned integer

const WORD32 INITIALPC        = 0X00000000;  // initial value of PC

/*
   Since SP *always* points-to (is the address-of) byte1 of the top-of-stack WORD32, the following statements are true
      * memory[SP] is byte1 of top-of-stack
      * "push WORD32" is accomplished by SP = SP+4, memory[SP] = WORD32
      * " pop WORD32" is accomplished by WORD32 = memory[SP], SP = SP-4 
      * for the run-time stack to begin at 0X00080000, SP must be initialized to
           0X00080000-0X00000004 = 0X0007FFFC
      * SP = 0X0007FFFC means that the run-time stack is empty; when run-time stack is empty, then the
           top-of-stack WORD32 does not exist
*/

const WORD32 INITIALSP        = 0X0007FFFC;  // initial value of SP (stack size = MAXMEMORYADDRESS-(INITIALSP+4)+1)

const WORD32 MINMEMORYADDRESS = 0X00000000;  // minimum usable memory address
const WORD32 MAXMEMORYADDRESS = 0X000FFFFF;  // maximum usable memory address

#define BYTE1(word) ( (BYTE) ((0XFF000000 & word) >> 24) )
#define BYTE2(word) ( (BYTE) ((0X00FF0000 & word) >> 16) )
#define BYTE3(word) ( (BYTE) ((0X0000FF00 & word) >>  8) )
#define BYTE4(word) ( (BYTE) ( 0X000000FF & word)        )
#define TOWORD32(byte1,byte2,byte3,byte4) ( (((WORD32) byte1) << 24) |     \
                                            (((WORD32) byte2) << 16) |     \
                                            (((WORD32) byte3) <<  8) |     \
                                            (((WORD32) byte4))             \
                                          )

enum STATE { RUN,STOP };

//====================================================
struct MICROINSTRUCTION
//====================================================
{
private:
   bool isFree;
   BIT BBus[4];
   BIT memoryOperation[3];
   BIT CBus[12];
   BIT ALUShifterControl[10];
   BIT JAM[4];
   BIT nextAddress[9];

public:
   //----------------------------------------------------
   MICROINSTRUCTION(const BIT BBus[] = "0000",
                    const BIT memoryOperation[] = "0000",
                    const BIT CBus[] = "000000000000",
                    const BIT ALUShifterControl[] = "0000000000",
                    const BIT JAM[] = "0000",
                    const BIT nextAddress[] = "000000000")
   //----------------------------------------------------
   {
      int i;

      for (i = 0; i <=  3; i++)
         this->BBus[i] = BBus[i];
      for (i = 0; i <=  2; i++)
         this->memoryOperation[i] = memoryOperation[i];
      for (i = 0; i <=  11; i++)
         this->CBus[i] = CBus[i];
      for (i = 0; i <=  9; i++)
         this->ALUShifterControl[i] = ALUShifterControl[i];
      for (i = 0; i <=  3; i++)
         this->JAM[i] = JAM[i];
      for (i = 0; i <=  8; i++)
         this->nextAddress[i] = nextAddress[i];
   }

   //----------------------------------------------------
   void SetIsFree(bool isFree)
   //----------------------------------------------------
   {
      this->isFree = isFree;
   }

   //----------------------------------------------------
   bool GetIsFree()
   //----------------------------------------------------
   {
      return( isFree );
   }

   //----------------------------------------------------
   char *GetBBus()
   //----------------------------------------------------
   {
      return( BBus );
   }

   //----------------------------------------------------
   char *GetMemoryOperation()
   //----------------------------------------------------
   {
      return( memoryOperation );
   }

   //----------------------------------------------------
   char *GetCBus()
   //----------------------------------------------------
   {
      return( CBus );
   }

   //----------------------------------------------------
   char *GetALUShifterControl()
   //----------------------------------------------------
   {
      return( ALUShifterControl );
   }

   //----------------------------------------------------
   char *GetJAM()
   //----------------------------------------------------
   {
      return( JAM );
   }

   //----------------------------------------------------
   char *GetNextAddress()
   //----------------------------------------------------
   {
      return( nextAddress );
   }

// operator<<() function is never referenced!
   friend ostream &operator<<(ostream &OUT,MICROINSTRUCTION &microinstruction);
};

//----------------------------------------------------
ostream &operator<<(ostream &OUT,MICROINSTRUCTION &microinstruction)
//----------------------------------------------------
{
   for (int i = 0; i <=  3; i++) OUT << microinstruction.BBus[i];               OUT << ' ';
   for (int i = 0; i <=  2; i++) OUT << microinstruction.memoryOperation[i];    OUT << ' ';
   for (int i = 0; i <= 11; i++) OUT << microinstruction.CBus[i];               OUT << ' ';
   for (int i = 0; i <=  9; i++) OUT << microinstruction.ALUShifterControl[i];  OUT << ' ';
   for (int i = 0; i <=  3; i++) OUT << microinstruction.JAM[i];                OUT << ' ';
   for (int i = 0; i <=  8; i++) OUT << microinstruction.nextAddress[i];
   return( OUT );
}

//====================================================
template <int SIZEOFTABLE,int MAXIMUMLENGTHIDENTIFIER>
struct IDENTIFIERTABLE
//====================================================
{
public:
   int size;
   WORD32 addresses[SIZEOFTABLE+1];
   bool isHWInstructionLabel[SIZEOFTABLE+1];
   char identifiers[SIZEOFTABLE+1][MAXIMUMLENGTHIDENTIFIER+1];

   //----------------------------------------------------
   IDENTIFIERTABLE()
   //----------------------------------------------------
   {
      size = 0;
   }

   //----------------------------------------------------
   void AddToTable(char lexeme[],WORD32 address,bool isHWInstructionLabel)
   //----------------------------------------------------
   {
      void DisplayMessage(const char message[],bool abort);
      
      if ( size <= SIZEOFTABLE )
      {
         size++;
         addresses[size] = address;
         this->isHWInstructionLabel[size] = isHWInstructionLabel;
         strncpy(identifiers[size],lexeme,MAXIMUMLENGTHIDENTIFIER);
      }
      else
         DisplayMessage((char *) "Identifier table overflow\n",true);
   }

   //----------------------------------------------------
   bool IsInTable(char lexeme[])
   //----------------------------------------------------
   {
      bool inTable;
      char uLexeme[LINELENGTH+1];
      int index;

      for (int i = 0; i <= (int) strlen(lexeme); i++)
         uLexeme[i] = toupper(lexeme[i]);
      inTable = false;
      index = 1;
      while ( !inTable && (index <= size) )
      {
         char uIdentifier[MAXIMUMLENGTHIDENTIFIER];

         for (int i = 0; i <= (int) strlen(identifiers[index]); i++)
            uIdentifier[i] = toupper(identifiers[index][i]);
         if ( strncmp(uIdentifier,uLexeme,MAXIMUMLENGTHIDENTIFIER) == 0 )
            inTable = true;
         else
            index++;
      }
      return( inTable );
   }

   //----------------------------------------------------
   bool IsInTable(WORD32 address)
   //----------------------------------------------------
   {
      bool inTable;
      int index;

      inTable = false;
      index = 1;
      while ( !inTable && (index <= size) )
      {
         if ( addresses[index] == address )
            inTable = true;
         else
            index++;
      }
      return( inTable );
   }

   //----------------------------------------------------
   int IndexInTable(char lexeme[])
   //----------------------------------------------------
   {
      void DisplayMessage(const char message[],bool abort);

      bool inTable;
      char uLexeme[LINELENGTH+1];
      int index;

      for (int i = 0; i <= (int) strlen(lexeme); i++)
         uLexeme[i] = toupper(lexeme[i]);
      inTable = false;
      index = 1;
      while ( !inTable && (index <= size) )
      {
         char uIdentifier[MAXIMUMLENGTHIDENTIFIER];

         for (int i = 0; i <= (int) strlen(identifiers[index]); i++)
            uIdentifier[i] = toupper(identifiers[index][i]);
         if ( strncmp(uIdentifier,uLexeme,MAXIMUMLENGTHIDENTIFIER) == 0 )
            inTable = true;
         else
            index++;
      }

      if ( !inTable )
      {
         char message[80+1];
         
         sprintf(message,"\"%s\" not found in table\n",lexeme);
         DisplayMessage(message,true);
      }
      return( index );
   }

   //----------------------------------------------------
   int IndexInTable(WORD32 address)
   //----------------------------------------------------
   {
      void DisplayMessage(const char message[],bool abort);

      bool inTable;
      int index;

      inTable = false;
      index = 1;
      while ( !inTable && (index <= size) )
      {
         if ( addresses[index] == address )
            inTable = true;
         else
            index++;
      }

      if ( !inTable )
      {
         char message[80+1];
         
         sprintf(message,"Identifier at 0X%08X not found in table\n",address);
         DisplayMessage(message,true);
      }

      return( index );
   }
};

//====================================================
// GLOBAL VARIABLES (OUCH?!)
//====================================================
IDENTIFIERTABLE<500,128> identifierTable;
ofstream OUTPUT;

BYTE mainMemory[MAXMEMORYADDRESS+1];
bool TRACE_MICROINSTRUCTIONS;

//----------------------------------------------------
int main()
//----------------------------------------------------
{
   void LoadObjectFile(ifstream &OBJECT);
   void LoadControlStore(MICROINSTRUCTION controlStore[],char fileName[]);
   void ExecuteObjectProgram(MICROINSTRUCTION controlStore[]);

   MICROINSTRUCTION controlStore[512];
   char fileName[80+1];
   char cont = 'n';

   char OUTPUTFileName[80 + 1];
   char objectFileName[80 + 1];
   ifstream OBJECT;

   cout << "Mic1 Simulation - Version " << MIC1_VERSION << "\n\n";
   do
   {
      try {
          cout << "Object fileName? ";
          cin >> fileName;

          strcpy(objectFileName,fileName);
          strcat(objectFileName,".object");
          OBJECT.open(objectFileName,ios::in);
          if (!OBJECT.is_open())
              throw invalid_argument("Error opening given file name's object file.");
          else
          {
              cout << "Using object file \"" << objectFileName << "\"" << endl;
              LoadObjectFile(OBJECT);
              OBJECT.close();

              strcpy(OUTPUTFileName, fileName);
              strcat(OUTPUTFileName, ".output");
              OUTPUT.open(OUTPUTFileName, ios::out);
              cout << "Using output file \"" << OUTPUTFileName << "\"" << endl;

              LoadControlStore(controlStore, fileName);

              char YOrN;
              do
              {
                  cout << "Trace Microinstructions? (y/n): ";
                  cin >> YOrN;
              } while (!((toupper(YOrN) == 'Y') || (toupper(YOrN) == 'N')));
              TRACE_MICROINSTRUCTIONS = (toupper(YOrN) == 'Y');

              ExecuteObjectProgram(controlStore);
              OUTPUT.close();
          }
      }
      catch (const std::invalid_argument &e) {
           cout << "A invalid argurment exception has occurred: '" << e.what() << "'." << endl;
      }
      catch (const std::exception& e) {
          cout << "A unhandled exception has occurred: '" << e.what() << "'." << endl;
      }
      cout << "\nContinue Simulation? (y/n): "; cin >> cont;
   } while (tolower(cont) == 'y');
   cout << "Exiting Simulation." << endl;
   return( 0 );
}

//--------------------------------------------------
void LoadObjectFile(ifstream &OBJECT)
//--------------------------------------------------
{
   void WriteMainMemoryByte(WORD32 address,BYTE byte);
/*
   Input identifier table (used for TRACE-ing machine instructions)

record 1: DDD
       2: 0XHHHHHHHH *AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
       3: 0XHHHHHHHH  AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
       .       . .
       .       . .
  size+1: 0XHHHHHHHH *AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
*/
   int size;
   WORD32 address;
   
   OBJECT >> size;
   for (int i = 1; i <= size; i++)
   {
      char identifier[LINELENGTH+1];
      
      OBJECT >> hex >> address;
      OBJECT >> identifier;
      if ( identifier[0] == '*' )
         identifierTable.AddToTable(&identifier[1],address, true);
      else
         identifierTable.AddToTable(&identifier[0],address,false);

   }
/*
   Input hexadecimal object code

0XHHHHHHHH: is the hexadecimal main memory address of the first of 1 or more 2-nibble bytes

0X00000000: HH HH HH ... HH
     .
     .
0XHHHHHHHH: HH HH HH ... HH
*/

// Initialize main memory with random bits
   for (address = MINMEMORYADDRESS; address <= MAXMEMORYADDRESS; address++)
      WriteMainMemoryByte(address,(BYTE) (rand()%255));

// Read object code records until EOF
   while ( OBJECT >> hex >> address )
   {
      char record[128+1];
      char *precord;
      int byte;

      OBJECT.ignore(5,':');
      OBJECT.getline(record,128);
      precord = strtok(record," ");
      while ( precord != NULL )
      {
         sscanf(precord,"%2X",&byte);
         WriteMainMemoryByte(address,(BYTE) byte);
         address++;
         precord = strtok(NULL," ");
      }
   }
}

//--------------------------------------------------
void LoadControlStore(MICROINSTRUCTION controlStore[],char fileName[])
//--------------------------------------------------
{
   void DisplayMessage(const char message[],bool abort);

/*
0XHHH: is the hexadecimal control store address of the 42-BIT, 6-field 
   microinstruction composed of bits BB...B
   
0X000: BBBB BBB BBBBBBBBBBBB BBBBBBBBBB BBBB BBBBBBBBBB
0X001: BBBB BBB BBBBBBBBBBBB BBBBBBBBBB BBBB BBBBBBBBBB
  .
  .
0XHHH: BBBB BBB BBBBBBBBBBBB BBBBBBBBBB BBBB BBBBBBBBBB
*/
   int address;
   BIT BBus[4+1];
   BIT memoryOperation[3+1];
   BIT CBus[12+1];
   BIT ALUShifterControl[10+1];
   BIT JAM[4+1];
   BIT nextAddress[9+1];

   ifstream CS;
   char CSFileName[80+1];

/*
   Try "Mic1.cs" and fileName+".cs" (in that order) as default control store 
      file names--when not found prompt user for control store file name.
*/

   //strcpy(CSFileName,"Mic1.cs");
   //CS.open(CSFileName,ios::in);
   if ( !CS.is_open() )
   {
      strcpy(CSFileName,fileName);
      strcat(CSFileName,".cs");
      CS.open(CSFileName,ios::in);
      if ( !CS.is_open() )
      {
         do
         {
            cout << "Control store fileName? ";
            cin >> CSFileName;
            strcat(CSFileName,".cs");
            CS.open(CSFileName,ios::in);
            if ( !CS.is_open() )
            {
               cout << "\"" << CSFileName << "\" not found!" << endl;
            }
         } while ( !CS.is_open() );
      }
   }
   CS.clear();
   cout << "Using control store file \"" << CSFileName << "\"" << endl;

   for (address = 0X00; address <= 0X1FF; address++)
      controlStore[address].SetIsFree(true);
   while ( CS >> hex >> address )
   {
      if ( !controlStore[address].GetIsFree() )
         DisplayMessage("Duplicate microcode addresses",true);
      CS.ignore(5,':');
      CS >> BBus >> memoryOperation >> CBus >> ALUShifterControl >> JAM >> nextAddress;
      CS.ignore(128,'\n');
      controlStore[address] = MICROINSTRUCTION(BBus,memoryOperation,CBus,ALUShifterControl,JAM,nextAddress);
      controlStore[address].SetIsFree(false);
   }
   CS.close();
}

//--------------------------------------------------
void ExecuteObjectProgram(MICROINSTRUCTION controlStore[])
//--------------------------------------------------
{
   void ExecuteALUShifterOperations(WORD32 ALUB,WORD32 H,BIT ALUShifterControl[],
                                    WORD32 &ALUC,BIT &N,BIT &Z,BIT &P);
   void DisplayDisassembledISAInstruction(WORD32 PC,BYTE opCode,WORD32 SP);
   void DisplayDisassembledMIR(MICROINSTRUCTION MIR,WORD32 T1);
   void DisplayHexString(ostream &OUT,WORD32 x,int nibbles,bool withPrefix);
   void DisplayMessage(const char message[],bool abort);
   WORD32 Integer(const BIT bits[],int length);
   void WriteMainMemoryByte(WORD32 address,BYTE byte);
   void ReadMainMemoryByte(WORD32 address,BYTE &byte);
   void PeekStack(WORD32 SP,int offset,WORD32 &word);
      
   STATE state;
   int cycle,FCycle,RCycle,WCycle,HWInstructions;
   bool FIng,RIng,WIng;
   WORD32 WData;
   WORD32 FAddress,RAddress,WAddress;
   char terminalOUT[256+1];

   WORD32 MAR;
   WORD32 MDR;    
   WORD32 PC;
   BYTE   MBR;                // MBRU is the unsigned "interpretation" of MBR
   WORD32 SP;
   WORD32 LV;
   WORD32 CPP;
   WORD32 TOS;
   WORD32 OPC;                // T0 is alias of OPC
   WORD32 H;
   WORD32 T1;                 // (NEW) Mic-1 temporary register
   WORD32 T2;                 // (NEW) Mic-1 temporary register
   WORD32 T3;                 // (NEW) Mic-1 temporary register

   WORD32 ALUB;
   WORD32 ALUC;
   BIT N,Z;
   BIT P;                     // (NEW) Mic-1 ALU status bit

   MICROINSTRUCTION MIR;
   WORD32 MPC;

   MAR = MDR = LV = CPP = TOS = OPC = H = T1 = T2 = T3 = 0X00000000;
   PC = INITIALPC;            // first ISA instruction *MUST* be found at 0X00000000
   SP = INITIALSP;            // run-time stack starts at 0X00080000 but is initialized to 0X0007FFFC

   MPC = 0X100;               // 0X100 is the control store address of main1 loop
   ReadMainMemoryByte(PC,MBR);

   if ( TRACE_MICROINSTRUCTIONS )
   {
      OUTPUT << "F(";
      DisplayHexString(OUTPUT,PC,8,false);
      OUTPUT << ") = ";
      DisplayHexString(OUTPUT,(WORD32) MBR,2,false);
      OUTPUT << endl;
   }

   state = RUN;
   cycle = 0;
   HWInstructions = 0;
   FIng = false;
   RIng = false;
   WIng = false;
   terminalOUT[0] = '\0';
   do
   {
// 1. Load MIR with next microinstruction
      MIR = controlStore[MPC];

   // Is microcode flow-of-control at top-of main1 loop?!
      if ( MPC == 0X100 )
      {
         int opCode = MBR;
         
         if ( controlStore[MPC].GetIsFree() )
         {
            char errorMessage[80+1];
            
            sprintf(errorMessage,"MPC = 0X%03X does not contain a microinstruction",MPC);
            DisplayMessage(errorMessage,true);
         }
   
         if ( TRACE_MICROINSTRUCTIONS )
               OUTPUT << "====================================================================================" << endl
                      << "    TOS0     TOS1     TOS2     TOS3        SP       PC Assembly instruction" << endl;
         else
         {
/*
   Disassembled ISA instruction displayed by DisplayDisassembledISAInstruction() (see immediately below)
          1111111112222222222333333333344444444445555555555666
12345678901234567890123456789012345678901234567890123456789012
    TOS0     TOS1     TOS2     TOS3        SP       PC Assembly instruction
-------- -------- -------- --------  -------- -------- ----------------------------------------
HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH  HHHHHHHH HHHHHHHH LLLLLLLLLLLLLLLL AAAAAAAA AAA...AAA
*/
            if ( HWInstructions%15 == 0 )
               OUTPUT << endl
                      << "    TOS0     TOS1     TOS2     TOS3        SP       PC Assembly instruction" << endl
                      << "-------- -------- -------- --------  -------- -------- ----------------------------------------" << endl;
         }

         DisplayDisassembledISAInstruction(PC,opCode,SP);
         HWInstructions++;

         if ( TRACE_MICROINSTRUCTIONS )
            OUTPUT << "====================================================================================" << endl;
      }

      if ( TRACE_MICROINSTRUCTIONS )
      {
/*
Cycle#       PC MBR      MAR      MDR       SP      TOS       LV      CPP   OPC/T0 MPC  JAM Next Mem BBus Shift ALU      CBus
------ -------- --- -------- -------- -------- -------- -------- -------- -------- --- ---- ---- --- ---- ----- -------- ----
DDDDD: HHHHHHHH  HH HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH HHH CNZP  HHH FRW AAAA AAAA  AAAAAAAA AAA...AAA
*/
         if ( cycle%15 == 0 )
         {
            OUTPUT << endl 
                   << "Cycle        PC MBR      MAR      MDR       SP      TOS       LV      CPP   OPC/T0 MPC  JAM Next Mem BBus Shift ALU      CBus"
                   << endl
                   << "------ -------- --- -------- -------- -------- -------- -------- -------- -------- --- ---- ---- --- ---- ----- -------- ----"
                   << endl;
         }
         OUTPUT << setw(5) << dec << right << cycle << ":";
         OUTPUT <<  " "; DisplayHexString(OUTPUT, PC,8,false);
         OUTPUT << "  "; DisplayHexString(OUTPUT,(WORD32) MBR,2,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,MAR,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,MDR,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT, SP,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,TOS,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT, LV,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,CPP,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,OPC,8,false);
         OUTPUT <<  " "; DisplayHexString(OUTPUT,(WORD32) MPC,3,false);
         DisplayDisassembledMIR(MIR,T1);
         OUTPUT << endl;
      }

/*
      The SVC instruction's last microinstruction's ALU field is "000001"
         T1 holds service request number
*/
      if      ( (MIR.GetALUShifterControl()[4] == '0') &&
                (MIR.GetALUShifterControl()[5] == '0') &&
                (MIR.GetALUShifterControl()[6] == '0') &&
                (MIR.GetALUShifterControl()[7] == '0') &&
                (MIR.GetALUShifterControl()[8] == '0') &&
                (MIR.GetALUShifterControl()[9] == '1') )
      {
         switch ( T1 )
         {
            case 1: // Terminate program (no parameter required)
               {
                  WORD32 word;
                  
                  if ( strlen(terminalOUT) > 0 )
                  {
                     cout   << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                     OUTPUT << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                  }
                  terminalOUT[0] = '\0';
                  
                  cout   << "\nSVC_STOP_PROGRAM_EXECUTION: Mic1 stopped" << endl;
                  OUTPUT << "\nSVC_STOP_PROGRAM_EXECUTION: Mic1 stopped" << endl;
                  state = STOP;
               }
               break;
            case 2: // Input a 32-bit, base 10 2's complement integer from terminal into memory[address] (address "peeked" from top-of-stack)
               {
                  WORD32 address;
                  WORD32 word;
                  char data[256+1];

                  if ( strlen(terminalOUT) > 0 )
                     cout   << terminalOUT;

                  cin >> dec >> word;
                  PeekStack(SP,0,address);
                  WriteMainMemoryByte(address+0,BYTE1(word));
                  WriteMainMemoryByte(address+1,BYTE2(word));
                  WriteMainMemoryByte(address+2,BYTE3(word));
                  WriteMainMemoryByte(address+3,BYTE4(word));

                  sprintf(data,"%d",word);
                  OUTPUT << "**********" << endl;
                  OUTPUT << terminalOUT << data << endl;
                  OUTPUT << "**********" << endl;
                  terminalOUT[0] = '\0';
               }
               break;
            case 3: // Output a 32-bit, base 10 2's complement integer to terminal (integer "peeked" from top-of-stack)
               {
                  WORD32 word;
                  char data[256+1];
                  
                  PeekStack(SP,0,word);
                  
                  sprintf(data,"%d",word);
                  if ( (strlen(data)+strlen(terminalOUT)) > 256 )
                  {
                     cout   << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                     OUTPUT << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                     terminalOUT[0] = '\0';
                  }
                  strcat(terminalOUT,data);
               }
               break;
            case 4: // Input a 32-bit, base 16 unsigned integer from terminal into memory[address] (address "peeked" from top-of-stack)
               {
                  WORD32 address;
                  unsigned int uword;

                  char data[256+1];

                  if ( strlen(terminalOUT) > 0 )
                     cout   << terminalOUT;

                  cin >> hex >> uword;
                  PeekStack(SP,0,address);
                  WriteMainMemoryByte(address+0,BYTE1(uword));
                  WriteMainMemoryByte(address+1,BYTE2(uword));
                  WriteMainMemoryByte(address+2,BYTE3(uword));
                  WriteMainMemoryByte(address+3,BYTE4(uword));

                  sprintf(data,"%08X",uword);
                  OUTPUT << "**********" << endl;
                  OUTPUT << terminalOUT << data << endl;
                  OUTPUT << "**********" << endl;
                  terminalOUT[0] = '\0';
               }
               break;
            case 5: // Output a 32-bit, base 16 unsigned integer to terminal (integer "peeked" from top-of-stack)
               {
                  WORD32 word;
                  char data[256+1];
                  
                  PeekStack(SP,0,word);
                  
                  sprintf(data,"%08X",word);
                  if ( (strlen(data)+strlen(terminalOUT)) > 256 )
                  {
                     cout   << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                     OUTPUT << terminalOUT << endl;
                     OUTPUT << "**********" << endl;
                     terminalOUT[0] = '\0';
                  }
                  strcat(terminalOUT,data);
               }
               break;
            case 6: // Output a NUL-terminated string of ASCII characters to terminal (pointer-to string "peeked" from top-of-stack)
               {
                  WORD32 address;
                  BYTE byte;
                  int i;
                  
                  PeekStack(SP,0,address);
                  i = 0;
                  ReadMainMemoryByte((address+i),byte);
                  while ( byte != 0X00 )
                  {
                     int len = strlen(terminalOUT);
                     
                     if ( len == 256 )
                     {
                        cout   << terminalOUT << endl;
                        OUTPUT << "**********" << endl;
                        OUTPUT << terminalOUT << endl;
                        OUTPUT << "**********" << endl;
                        terminalOUT[0] = '\0';
                        len = 0;
                     }

                     terminalOUT[len] = (char) byte;
                     terminalOUT[len+1] = '\0';
                     i++;
                     ReadMainMemoryByte((address+i),byte);
                  }
               }
               break;
            case 7: // Output an end-of-line character to terminal (no parameter required)
               {
                  cout   << terminalOUT << endl;
                  OUTPUT << "**********" << endl;
                  OUTPUT << terminalOUT << endl;
                  OUTPUT << "**********" << endl;
               }
               terminalOUT[0] = '\0';
               break;
            default:
               DisplayMessage("Illegal service request number",false);
               break;
         }
      }
/*
      The ERROR instruction's microinstruction ALU field is "000100"
*/
      else if ( (MIR.GetALUShifterControl()[4] == '0') &&
                (MIR.GetALUShifterControl()[5] == '0') &&
                (MIR.GetALUShifterControl()[6] == '0') &&
                (MIR.GetALUShifterControl()[7] == '1') &&
                (MIR.GetALUShifterControl()[8] == '0') &&
                (MIR.GetALUShifterControl()[9] == '0') )
      {
         char message[80+1];
         
         sprintf(message,"ALU control *ERROR* at MPC = 0X%03X",MPC);
         DisplayMessage(message,true);
      }
      else
      {
// 2. Gate register onto B bus
         switch ( Integer(MIR.GetBBus(),4) )
         {
            case 0X0: ALUB = MDR; break;
            case 0X1: ALUB =  PC; break;
            case 0X2: ALUB = ( WORD32) MBR; break;  // sign-extended or (  WORD32) MBR when compiler error occurs 
            case 0X3: ALUB = (unsigned ) MBR; break;  // 0-fill        or (unsigned) MBR when compiler error occurs
            case 0X4: ALUB =  SP; break;
            case 0X5: ALUB =  LV; break;
            case 0X6: ALUB = CPP; break;
            case 0X7: ALUB = TOS; break;
            case 0X8: ALUB = OPC; break;
            case 0X9: ALUB =  T1; break;
            case 0XA: ALUB =  T2; break;
            case 0XB: ALUB =  T3; break;
             default: DisplayMessage("Illegal B-bus register",true);
         }

// 3. Execute ALU/shifter operations
         ExecuteALUShifterOperations(ALUB,H,MIR.GetALUShifterControl(),ALUC,N,Z,P);

// 4. Write register(s) with C bus value
         if ( MIR.GetCBus()[ 0] == '1' )
         {
            H   = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "  H" << " = "; DisplayHexString(OUTPUT,  H,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 1] == '1' ) 
         {
            OPC = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "OPC" << " = "; DisplayHexString(OUTPUT,OPC,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 2] == '1' ) 
         { 
            TOS  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "TOS" << " = "; DisplayHexString(OUTPUT,TOS,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 3] == '1' )
         { 
            CPP = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "CPP" << " = "; DisplayHexString(OUTPUT,CPP,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 4] == '1' ) 
         { 
            LV  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " LV" << " = "; DisplayHexString(OUTPUT, LV,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 5] == '1' )
         {
            if      ( ALUC < INITIALSP )
               DisplayMessage("Run-time stack underflow",false);
            else if ( ALUC > MAXMEMORYADDRESS-4 )
               DisplayMessage("Run-time stack overflow",false);
            SP  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " SP" << " = "; DisplayHexString(OUTPUT, SP,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 6] == '1' )
         {
            PC  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " PC" << " = "; DisplayHexString(OUTPUT, PC,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 7] == '1' )
         {
            MDR = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "MDR" << " = "; DisplayHexString(OUTPUT,MDR,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 8] == '1' )
         {
            MAR = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << "MAR" << " = "; DisplayHexString(OUTPUT,MAR,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[ 9] == '1' )
         {
            T1  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " T1" << " = "; DisplayHexString(OUTPUT, T1,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[10] == '1' )
         {
            T2  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " T2" << " = "; DisplayHexString(OUTPUT, T2,8,false); OUTPUT << endl;
            }
         }
         if ( MIR.GetCBus()[11] == '1' )
         {
            T3  = ALUC;
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << setw(3) << " T3" << " = "; DisplayHexString(OUTPUT, T3,8,false); OUTPUT << endl;
            }
         }
      }

      if ( state == RUN )
      {
   // 5. Determine MPC
         MPC = Integer(MIR.GetNextAddress(),9);
   //    5a) JMPC
         if ( MIR.GetJAM()[0] == '1' )
            MPC |= (MBR & 0X000001FF);
   //    5b) JAMN
         if ( MIR.GetJAM()[1] == '1' )
            if ( N == 1 ) MPC |= 0X00000100;
   //    5c) JAMZ
         if ( MIR.GetJAM()[2] == '1' )
            if ( Z == 1 ) MPC |= 0X00000100;
   //    5d) JAMP
         if ( MIR.GetJAM()[3] == '1' )
            if ( P == 1 ) MPC |= 0X00000100;
   
   // 6. Memory operations
   //    6a) Finish (F)etching
         if ( FIng && (cycle >= FCycle) )
         {
            FIng = false;
            ReadMainMemoryByte(FAddress,MBR);
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << "F(";
               DisplayHexString(OUTPUT,FAddress,8,false);
               OUTPUT << ") = "; DisplayHexString(OUTPUT,(WORD32) MBR,2,false);
               OUTPUT << endl;
            }         
         }
   //    6b) Start (F)etching
         if ( MIR.GetMemoryOperation()[0] == '1' )
            if ( FIng )
               DisplayMessage("Overlapped fetch memory operations",true);
            else
            {
               FIng = true;
               FCycle = cycle+1;
               FAddress = PC;
            }
   //    6c) Finish big-endian (R)eading 
         if ( RIng && (cycle >= RCycle) )
         {
            BYTE byte1,byte2,byte3,byte4;
            
            RIng = false;
            ReadMainMemoryByte(RAddress+0,byte1);
            ReadMainMemoryByte(RAddress+1,byte2);
            ReadMainMemoryByte(RAddress+2,byte3);
            ReadMainMemoryByte(RAddress+3,byte4);
            MDR = TOWORD32(byte1,byte2,byte3,byte4);
   
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << "R(";
               DisplayHexString(OUTPUT,RAddress,8,false);
               OUTPUT << ") = "; DisplayHexString(OUTPUT,MDR,8,false); OUTPUT << endl;
            }
         }
   //    6d) Finish big-endian (W)riting 
         if ( WIng && (cycle >= WCycle) )
         {
            WIng = false;
            WriteMainMemoryByte(WAddress+0,BYTE1(WData));
            WriteMainMemoryByte(WAddress+1,BYTE2(WData));
            WriteMainMemoryByte(WAddress+2,BYTE3(WData));
            WriteMainMemoryByte(WAddress+3,BYTE4(WData));
   
            if ( TRACE_MICROINSTRUCTIONS )
            {
               OUTPUT << "W(";
               DisplayHexString(OUTPUT,WAddress,8,false);
               OUTPUT << ") = "; DisplayHexString(OUTPUT,MDR,8,false); OUTPUT << endl;
            }
         }
   //    6e) Start (R)eading
         if ( MIR.GetMemoryOperation()[1] == '1' )
            if ( RIng || WIng )
               DisplayMessage("Overlapped read/write memory operations",true);
            else
            {
               RIng = true;
               RCycle = cycle+1;
               RAddress = MAR;
            }
   //    6f) Start (W)riting
         if ( MIR.GetMemoryOperation()[2] == '1' )
            if ( RIng || WIng )
               DisplayMessage("Overlapped read/write memory operations",true);
            else
            {
               WIng = true;
               WCycle = cycle+1;
               WAddress = MAR;
               WData = MDR;
            }
   // Update cycle
         cycle++;
      }
   } while ( state == RUN );
}

//--------------------------------------------------
void PeekStack(WORD32 SP,int offset,WORD32 &word)
//--------------------------------------------------
{
/*
   The top-of-stack word is at offset 0, the word immediately under top-of-stack
      is at offset 1, et cetera.
*/
   void ReadMainMemoryByte(WORD32 address,BYTE &byte);
   void DisplayMessage(const char message[],bool abort);
   
   BYTE byte1,byte2,byte3,byte4;

   if ( (SP-4*offset) < INITIALSP )
      DisplayMessage((char *) "Run-time stack underflow",false);

   ReadMainMemoryByte(SP-4*offset+0,byte1);
   ReadMainMemoryByte(SP-4*offset+1,byte2);
   ReadMainMemoryByte(SP-4*offset+2,byte3);
   ReadMainMemoryByte(SP-4*offset+3,byte4);
   word = TOWORD32(byte1,byte2,byte3,byte4);
}

//--------------------------------------------------
void ExecuteALUShifterOperations(WORD32 ALUB,WORD32 H,BIT ALUShifterControl[],
                                 WORD32 &ALUC,BIT &N,BIT &Z,BIT &P)
//--------------------------------------------------
{
   void DoFullAdder(WORD32 LHS,WORD32 RHS,BIT carryIn,WORD32 &sum);
   void DisplayMessage(const char message[],bool abort);
   WORD32 Integer(const BIT bits[],int length);

// Compare Figures 4-2 and 4-16: A/B in 4-2 corresponds to H/SOURCE in 4-16

// Do ALU operation
   int ALUOperation = Integer(&ALUShifterControl[4],6);
   
   if      ( ALUOperation == Integer("011000",6) ) // H
      ALUC = H;
   else if ( ALUOperation == Integer("010100",6) ) // B
      ALUC = ALUB;
   else if ( ALUOperation == Integer("011010",6) ) // not H
      ALUC = ~H;
   else if ( ALUOperation == Integer("101100",6) ) // not B
      ALUC = ~ALUB;
   else if ( ALUOperation == Integer("111100",6) ) // H+B
      DoFullAdder(H,ALUB,0,ALUC);
   else if ( ALUOperation == Integer("111101",6) ) // H+B+1
      DoFullAdder(H,ALUB,1,ALUC);
   else if ( ALUOperation == Integer("111001",6) ) // H+1
      DoFullAdder(H,1,0,ALUC);
   else if ( ALUOperation == Integer("110101",6) ) // B+1
      DoFullAdder(ALUB,1,0,ALUC);
   else if ( ALUOperation == Integer("111111",6) ) // B-H
      DoFullAdder(ALUB,~H,1,ALUC);
   else if ( ALUOperation == Integer("110110",6) ) // B-1
      DoFullAdder(ALUB,-1,0,ALUC);
   else if ( ALUOperation == Integer("111011",6) ) // -H
      DoFullAdder(~H,0,1,ALUC);
   else if ( ALUOperation == Integer("001100",6) ) // H and B
      ALUC = H & ALUB;
   else if ( ALUOperation == Integer("011100",6) ) // H or B
      ALUC = H | ALUB;
   else if ( ALUOperation == Integer("010000",6) ) // 0
      ALUC = 0;
   else if ( ALUOperation == Integer("010001",6) ) // 1
      ALUC = 1;
   else if ( ALUOperation == Integer("010010",6) ) // -1
      ALUC = -1;
   else if ( ALUOperation == Integer("000010",6) ) // H cmp B
   {
      if       ( (signed int) H   < (signed int) ALUB )
         ALUC = -1;
      else if  ( (signed int) H  == (signed int) ALUB )
         ALUC = 0;
      else//if ( (signed int) H   > (signed int) ALUB )
         ALUC = 1;
   }
   else if ( ALUOperation == Integer("000011",6) ) // H cmpu B
   {
      if       ( (unsigned int) H   < (unsigned int) ALUB )
         ALUC = -1;
      else if  ( (unsigned int) H  == (unsigned int) ALUB )
         ALUC = 0;
      else//if ( (unsigned int) H   > (unsigned int) ALUB )
         ALUC = 1;
   }
   else if ( ALUOperation == Integer("000101",6) ) // B+4
      DoFullAdder(ALUB,4,0,ALUC);
   else if ( ALUOperation == Integer("000110",6) ) // B-4
      DoFullAdder(ALUB,-4,0,ALUC);
   else
   {
      DisplayMessage("Illegal ALU operation",true);
      ALUC = 0;
   }

// Compute N,Z,P condition codes
   N = (ALUC >> 31) & 0X1;
   Z = (ALUC == 0) ? 1 : 0; 
   P = ((N == 0) && (Z == 0)) ? 1 : 0;

// Do 1 shifter operation (at most 1 shifter bit can be '1')
   int shiftOperation = Integer(&ALUShifterControl[0],4);
   
   if ( (shiftOperation !=  8) &&
        (shiftOperation !=  4) &&
        (shiftOperation !=  2) &&
        (shiftOperation !=  1) &&
        (shiftOperation !=  0) )
      DisplayMessage("Illegal shift operation",true);
   else
   {
      if      ( ALUShifterControl[0] == '1' ) // SL8
         ALUC <<= 8;
      else if ( ALUShifterControl[1] == '1' ) // SRA1
         ALUC >>= 1;
      else if ( ALUShifterControl[2] == '1' ) // SRL1
         ALUC = ((unsigned) ALUC) >> 1;
      else if ( ALUShifterControl[3] == '1' ) // SL1
         ALUC <<= 1;
      else
         /* No shift operation */;
   }
}

//--------------------------------------------------
void DoFullAdder(WORD32 LHS,WORD32 RHS,BIT carryIn,WORD32 &sum)
//--------------------------------------------------
{
   sum = LHS+RHS+carryIn; 
}

//--------------------------------------------------
void DisplayDisassembledISAInstruction(WORD32 PC,BYTE opCode,WORD32 SP)
//--------------------------------------------------
{
   void DisplayHexString(ostream &OUT,WORD32 x,int nibbles,bool withPrefix);
   WORD32 Integer(const BIT bits[],int length);
   void ReadMainMemoryByte(WORD32 address,BYTE &byte);
   void PeekStack(WORD32 SP,int offset,WORD32 &word);

/*
          111111111222222222233333333334444444444555555555566666666667
1234567890123456789012345678901234567890123456789012345678901234567890
    TOS0     TOS1     TOS2     TOS3        SP       PC Assembly instruction
-------- -------- -------- --------  -------- -------- ----------------------------------------
HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH  HHHHHHHH HHHHHHHH LLLLLLLLLLLLLLLL AAAAAAAA AAA...AAA
*/

//-------------------------------------------------------------
// *Note* OPERANDTYPE, HWOPERATIONRECORD, and HWOperationTable[] are 
//    copied from Mic1Assembler.cpp
//-------------------------------------------------------------
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
   
   struct HWOPERATIONRECORD
   {
      int opCode;
      int sizeInBytes;
      char mnemonic[8+1];    // *CUIDADO* increase size for longer-than-8-character mnemonics
//    TOKEN token;           // token field is *not* needed by Mic1.cpp
      OPERANDTYPE operandType;   
   };

   //========================================
   static const HWOPERATIONRECORD HWOperationTable[] = 
   //========================================
   {
      { 0X00,1,"NOOP"    ,/*NOOP    ,*/NONE   },
      { 0X01,6,"PUSH"    ,/*PUSH    ,*/MEMORY },
      { 0X02,6,"PUSHA"   ,/*PUSHA   ,*/MEMORY },
      { 0X03,6,"POP"     ,/*POP     ,*/MEMORY },
      { 0X04,5,"DISCARD" ,/*DISCARD ,*/IMMO32 },
      { 0X05,1,"SWAP"    ,/*SWAP    ,*/NONE   },
      { 0X06,1,"MAKEDUP" ,/*MAKEDUP ,*/NONE   },
      { 0X07,1,"PUSHLV"  ,/*PUSHLV  ,*/NONE   },
      { 0X08,1,"POPLV"   ,/*POPLV   ,*/NONE   },
      { 0X09,1,"PUSHSP"  ,/*PUSHSP  ,*/NONE   },
      { 0X0A,1,"POPSP"   ,/*POPSP   ,*/NONE   },
      { 0X0B,1,"PUSHCPP" ,/*PUSHCPP ,*/NONE   },
      { 0X0C,1,"POPCPP"  ,/*POPCPP  ,*/NONE   },
      { 0X10,1,"ADD"     ,/*ADD     ,*/NONE   },
      { 0X11,1,"SUB"     ,/*SUB     ,*/NONE   },
      { 0X12,1,"NEG"     ,/*NEG     ,*/NONE   },
      { 0X13,1,"AND"     ,/*AND     ,*/NONE   },
      { 0X14,1,"OR"      ,/*OR      ,*/NONE   },
      { 0X15,1,"NOT"     ,/*NOT     ,*/NONE   },
      { 0X16,1,"CMP"     ,/*CMP     ,*/NONE   },
      { 0X17,1,"CMPU"    ,/*CMPU    ,*/NONE   },
      { 0X18,1,"SRA1"    ,/*SRA1    ,*/NONE   },
      { 0X19,1,"SL1"     ,/*SL1     ,*/NONE   },
      { 0X30,5,"JMP"     ,/*JMP     ,*/DIRO32 },
      { 0X31,5,"JMPL"    ,/*JMPL    ,*/DIRO32 },
      { 0X32,5,"JMPE"    ,/*JMPE    ,*/DIRO32 },
      { 0X33,5,"JMPG"    ,/*JMPG    ,*/DIRO32 },
      { 0X34,5,"JMPLE"   ,/*JMPLE   ,*/DIRO32 },
      { 0X35,5,"JMPGE"   ,/*JMPGE   ,*/DIRO32 },
      { 0X36,5,"JMPNE"   ,/*JMPNE   ,*/DIRO32 },
      { 0X37,5,"JMPT"    ,/*JMPT    ,*/DIRO32 },
      { 0X38,5,"JMPF"    ,/*JMPF    ,*/DIRO32 },
      { 0X3D,5,"CALL"    ,/*CALL    ,*/DIRO32 },
      { 0X3E,1,"RETURN"  ,/*RETURN  ,*/NONE   },
   //------------------------------------------------------------
   // Add new ISA instructions here...
   //------------------------------------------------------------
      { 0X3F,5,"SVC"     ,/*SVC     ,*/IMMO32 }
   };

   int i;
   bool found;

// Display the top 3 words on the run-time stack (if they exist), TOS0, TOS1, TOS2
// TOS0 = offset 0
   if ( SP >= INITIALSP+4 )
   {
      WORD32 TOS0;
      
      PeekStack(SP,0,TOS0);
      DisplayHexString(OUTPUT,TOS0,8,false);
   }
   else
      OUTPUT << " (empty)";
   OUTPUT << " ";

// TOS1 = offset 1
   if ( SP-4 >= INITIALSP+4 )
   {
      WORD32 TOS1;
      
      PeekStack(SP,1,TOS1);
      DisplayHexString(OUTPUT,TOS1,8,false);
   }
   else
      OUTPUT << "        ";
   OUTPUT << " ";

// TOS2 = offset 2
   if ( SP-8 >= INITIALSP+4 )
   {
      WORD32 TOS2;
      
      PeekStack(SP,2,TOS2);
      DisplayHexString(OUTPUT,TOS2,8,false);
   }
   else
      OUTPUT << "        ";
   OUTPUT << " ";

// TOS2 = offset 3
   if ( SP-12 >= INITIALSP+4 )
   {
      WORD32 TOS3;
      
      PeekStack(SP,3,TOS3);
      DisplayHexString(OUTPUT,TOS3,8,false);
   }
   else
      OUTPUT << "        ";
   OUTPUT << "  ";

// Display SP, PC, and instruction label (if it exists)
   DisplayHexString(OUTPUT,SP,8,false); OUTPUT << " ";
   DisplayHexString(OUTPUT,PC,8,false); OUTPUT << " ";
   if ( identifierTable.IsInTable(PC) )
   {
      int index = identifierTable.IndexInTable(PC);
      
      if ( identifierTable.isHWInstructionLabel[index] )
         OUTPUT << left << setw(16) << identifierTable.identifiers[index];
      else
         OUTPUT << left << setw(16) << " ";
   }
   else
      OUTPUT << left << setw(16) << " ";

// Find opCode in H/W operation table the display corresponding mnemonic
   i = 0;
   found = false;
   while ( (i <= sizeof(HWOperationTable)/sizeof(HWOPERATIONRECORD)-1) && !found )
   {
      if ( opCode == HWOperationTable[i].opCode )
         found = true;
      else
         i++;
   }
   if ( !found )
      OUTPUT << "????????";
   else
   {
      OUTPUT << left << setw(8) << HWOperationTable[i].mnemonic << " ";
   // Display operand field
      switch ( HWOperationTable[i].operandType )
      {
         case NONE: 
            break;
         case MEMORY: 
            {
               WORD32 O32;
               BYTE byte1,byte2,byte3,byte4,mode;
               bool shouldDisplayLabel;
               char label[LINELENGTH+1];
               
               ReadMainMemoryByte(PC+1,byte1);
               ReadMainMemoryByte(PC+2,byte2);
               ReadMainMemoryByte(PC+3,byte3);
               ReadMainMemoryByte(PC+4,byte4);
               O32 = TOWORD32(byte1,byte2,byte3,byte4);
               ReadMainMemoryByte(PC+5,mode);

               if ( identifierTable.IsInTable(O32) )
               {
                  int index = identifierTable.IndexInTable(O32);

                  if ( !identifierTable.isHWInstructionLabel[index] )
                  {
                     shouldDisplayLabel = true;
                     strcpy(label,identifierTable.identifiers[index]);
                  }
                  else
                     shouldDisplayLabel = false;
               }
               else
                  shouldDisplayLabel = false;

               switch ( mode )
               {
                  case 0X00: // memory immediate #<O32>
                     OUTPUT << "#";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        DisplayHexString(OUTPUT,O32,8,true);
                     break;
                  case 0X01: // memory direct <O32>
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        DisplayHexString(OUTPUT,O32,8,true);
                     break;
                  case 0X02: // memory indirect @<O32>
                     OUTPUT << "@";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        DisplayHexString(OUTPUT,O32,8,true);
                     break;
                  case 0X05: // SP-relative direct SP:<O32>
                     OUTPUT << "SP:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
                  case 0X09: // LV-relative direct LV:<O32>
                     OUTPUT << "LV:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
                  case 0X0D: // CPP-relative direct CPP:<O32>
                     OUTPUT << "CPP:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
                  case 0X06: // SP-relative indirect @SP:<O32>
                     OUTPUT << "@SP:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
                  case 0X0A: // LV-relative indirect @LV:<O32>
                     OUTPUT << "@LV:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
                  case 0X0E: // CPP-relative indirect @CPP:<O32>
                     OUTPUT << "@CPP:";
                     if ( shouldDisplayLabel )
                        OUTPUT << left << label;
                     else
                        OUTPUT << O32;
                     break;
               }
            }
            break;
         case DIRO32:
            {
               WORD32 O32;
               BYTE byte1,byte2,byte3,byte4;
               
               ReadMainMemoryByte(PC+1,byte1);
               ReadMainMemoryByte(PC+2,byte2);
               ReadMainMemoryByte(PC+3,byte3);
               ReadMainMemoryByte(PC+4,byte4);
               O32 = TOWORD32(byte1,byte2,byte3,byte4);

               if ( identifierTable.IsInTable(O32) )
               {
                  int index = identifierTable.IndexInTable(O32);

                  if ( identifierTable.isHWInstructionLabel[index] )
                     OUTPUT << left << identifierTable.identifiers[index];
                  else
                     DisplayHexString(OUTPUT,O32,8,true);
               }
               else
                  DisplayHexString(OUTPUT,O32,8,true);
            }
            break;
         case IMMO32:
            {
               WORD32 O32;
               BYTE byte1,byte2,byte3,byte4;
               
               ReadMainMemoryByte(PC+1,byte1);
               ReadMainMemoryByte(PC+2,byte2);
               ReadMainMemoryByte(PC+3,byte3);
               ReadMainMemoryByte(PC+4,byte4);
               O32 = TOWORD32(byte1,byte2,byte3,byte4);
               OUTPUT << "#" << O32;
            }
            break;
      }
   }
   OUTPUT << endl;
}

//--------------------------------------------------
void DisplayDisassembledMIR(MICROINSTRUCTION MIR,WORD32 T1)
//--------------------------------------------------
{
   void DisplayHexString(ostream &OUT,WORD32 x,int nibbles,bool withPrefix);
   WORD32 Integer(const BIT bits[],int length);

// JAM bits
   OUTPUT << " ";
   if ( MIR.GetJAM()[0] == '1' )
      OUTPUT << "C";
   else
      OUTPUT << " ";
   if ( MIR.GetJAM()[1] == '1' )
      OUTPUT << "N";
   else
      OUTPUT << " ";
   if ( MIR.GetJAM()[2] == '1' )
      OUTPUT << "Z";
   else
      OUTPUT << " ";
   if ( MIR.GetJAM()[3] == '1' )
      OUTPUT << "P";
   else
      OUTPUT << " ";
// Next address
   OUTPUT << "  ";
   DisplayHexString(OUTPUT,Integer(&MIR.GetNextAddress()[ 0],9),3,false);

// Memory operation(s)
   OUTPUT << " ";
   if ( MIR.GetMemoryOperation()[0] == '1' )
      OUTPUT << "F";
   else
      OUTPUT << " ";
   if ( MIR.GetMemoryOperation()[1] == '1' )
      OUTPUT << "R";
   else
      OUTPUT << " ";
   if ( MIR.GetMemoryOperation()[2] == '1' )
      OUTPUT << "W";
   else
      OUTPUT << " ";

// B bus register displayed when B bus is operand of ALU operation
   int ALUOperation = Integer(&MIR.GetALUShifterControl()[4],6);
   
   OUTPUT << " ";
   if (
        (ALUOperation == Integer("010100",6) ) || // B
        (ALUOperation == Integer("101100",6) ) || // not B
        (ALUOperation == Integer("111100",6) ) || // H+B
        (ALUOperation == Integer("111101",6) ) || // H+B+1
        (ALUOperation == Integer("110101",6) ) || // B+1
        (ALUOperation == Integer("111111",6) ) || // B-H
        (ALUOperation == Integer("110110",6) ) || // B-1
        (ALUOperation == Integer("001100",6) ) || // H and B
        (ALUOperation == Integer("011100",6) ) || // H or B
        (ALUOperation == Integer("000010",6) ) || // H cmp B
        (ALUOperation == Integer("000011",6) ) || // H cmpu B
        (ALUOperation == Integer("000101",6) ) || // B+4
        (ALUOperation == Integer("000110",6) )    // B-4
      )
   {
      switch ( Integer(MIR.GetBBus(),4) )
      {
         case 0X0: OUTPUT << "MDR "; break;
         case 0X1: OUTPUT << "PC  "; break;
         case 0X2: OUTPUT << "MBR "; break;
         case 0X3: OUTPUT << "MBRU"; break;
         case 0X4: OUTPUT << "SP  "; break;
         case 0X5: OUTPUT << "LV  "; break;
         case 0X6: OUTPUT << "CPP "; break;
         case 0X7: OUTPUT << "TOS "; break;
         case 0X8: OUTPUT << "OPC "; break;
         case 0X9: OUTPUT << "T1  "; break;
         case 0XA: OUTPUT << "T2  "; break;
         case 0XB: OUTPUT << "T3  "; break;
          default: OUTPUT << "????"; break;
      }
   }
   else
      OUTPUT << "    ";
// Shifter/ALU operation
   OUTPUT << " ";
   if      ( MIR.GetALUShifterControl()[0] == '1' )
      OUTPUT << "SL8 ";
   else if ( MIR.GetALUShifterControl()[1] == '1' )
      OUTPUT << "SRA1";
   else if ( MIR.GetALUShifterControl()[2] == '1' )
      OUTPUT << "SRL1";
   else if ( MIR.GetALUShifterControl()[3] == '1' )
      OUTPUT << "SL1 ";
   else
      OUTPUT << "    ";
   OUTPUT << "  ";
   if      ( ALUOperation == Integer("011000",6) ) // H
      OUTPUT << "H       ";
   else if ( ALUOperation == Integer("010100",6) ) // B
      OUTPUT << "B       ";
   else if ( ALUOperation == Integer("011010",6) ) // not H
      OUTPUT << "not H   ";
   else if ( ALUOperation == Integer("101100",6) ) // not B
      OUTPUT << "not B   ";
   else if ( ALUOperation == Integer("111100",6) ) // H+B
      OUTPUT << "H+B     ";
   else if ( ALUOperation == Integer("111101",6) ) // H+B+1
      OUTPUT << "H+B+1   ";
   else if ( ALUOperation == Integer("111001",6) ) // H+1
      OUTPUT << "H+1     ";
   else if ( ALUOperation == Integer("110101",6) ) // B+1
      OUTPUT << "B+1     ";
   else if ( ALUOperation == Integer("111111",6) ) // B-H
      OUTPUT << "B-H     ";
   else if ( ALUOperation == Integer("110110",6) ) // B-1
      OUTPUT << "B-1     ";
   else if ( ALUOperation == Integer("111011",6) ) // -H
      OUTPUT << "-H      ";
   else if ( ALUOperation == Integer("001100",6) ) // H and B
      OUTPUT << "H and B ";
   else if ( ALUOperation == Integer("011100",6) ) // H or B
      OUTPUT << "H or B  ";
   else if ( ALUOperation == Integer("010000",6) ) // 0
      OUTPUT << "0       ";
   else if ( ALUOperation == Integer("010001",6) ) // 1
      OUTPUT << "1       ";
   else if ( ALUOperation == Integer("010010",6) ) // -1
      OUTPUT << "-1      ";
// added ALU "operations"
   else if ( ALUOperation == Integer("000001",6) ) // SVC pseudo operation
      OUTPUT << "SVC#" << setw(2) << T1 << "  ";
   else if ( ALUOperation == Integer("000010",6) ) // H cmp B
      OUTPUT << "H cmp B ";
   else if ( ALUOperation == Integer("000011",6) ) // H cmpu B
      OUTPUT << "H cmpu B";
   else if ( ALUOperation == Integer("000100",6) ) // ERROR
      OUTPUT << "ERROR   ";
   else if ( ALUOperation == Integer("000101",6) ) // B+4
      OUTPUT << "B+4     ";
   else if ( ALUOperation == Integer("000110",6) ) // B-4
      OUTPUT << "B-4     ";
   else
      OUTPUT << "????????";

// C bus register(s)
   if ( MIR.GetCBus()[ 0] == '1' ) OUTPUT << " H";
   if ( MIR.GetCBus()[ 1] == '1' ) OUTPUT << " OPC";
   if ( MIR.GetCBus()[ 2] == '1' ) OUTPUT << " TOS";
   if ( MIR.GetCBus()[ 3] == '1' ) OUTPUT << " CPP";
   if ( MIR.GetCBus()[ 4] == '1' ) OUTPUT << " LV";
   if ( MIR.GetCBus()[ 5] == '1' ) OUTPUT << " SP";
   if ( MIR.GetCBus()[ 6] == '1' ) OUTPUT << " PC";
   if ( MIR.GetCBus()[ 7] == '1' ) OUTPUT << " MDR";
   if ( MIR.GetCBus()[ 8] == '1' ) OUTPUT << " MAR";
   if ( MIR.GetCBus()[ 9] == '1' ) OUTPUT << " T1";
   if ( MIR.GetCBus()[10] == '1' ) OUTPUT << " T2";
   if ( MIR.GetCBus()[11] == '1' ) OUTPUT << " T3";
}

//------------------------------------------------------------
void DisplayHexString(ostream &OUT,WORD32 x,int nibbles,bool withPrefix)
//------------------------------------------------------------
{
   char data[256+1];
   
   if ( withPrefix )
      sprintf(data,"0X%0*X",nibbles,x);
   else
      sprintf(data,"%0*X",nibbles,x);
   OUT << data;
}

//--------------------------------------------------
void DisplayMessage(const char message[],bool abort)
//--------------------------------------------------
{
// This line was added to Mic1Assembler.cpp and echo screen message to OUTPUT file
   OUTPUT << "***" << message << (abort ? "...aborting" : "") << endl;
   cout            << message << (abort ? "...aborting" : "") << endl;
   if ( abort )
   {
      system("PAUSE");
      exit(0);
   }
}

//----------------------------------------------------
WORD32 Integer(const BIT bits[],int length)
//----------------------------------------------------
{
   WORD32 r = 0X00000000;

   for (int i = 0; i <= length-1; i++)
      r = (r << 1) | ( (bits[i] == '0') ? 0X00000000 : 0X00000001 );
   return( r );
}

//----------------------------------------------------
void WriteMainMemoryByte(WORD32 address,BYTE byte)
//----------------------------------------------------
{
   void DisplayMessage(const char message[],bool abort);

   if ( (MINMEMORYADDRESS <= address) && (address <= MAXMEMORYADDRESS) )
      mainMemory[address] = byte;
   else
   {
      char message[80+1];
      
      sprintf(message,"Illegal memory write attempt! location 0X%08X, byte 0X%02X",address,byte);
      DisplayMessage(message,false);
   }
}

//----------------------------------------------------
void ReadMainMemoryByte(WORD32 address,BYTE &byte)
//----------------------------------------------------
{
   void DisplayMessage(const char message[],bool abort);
   
   if ( (MINMEMORYADDRESS <= address) && (address <= MAXMEMORYADDRESS) )
      byte = mainMemory[address];
   else
   {
      char message[80+1];
      
      sprintf(message,"Illegal memory read attempt! location 0X%08X",address);
      DisplayMessage(message,false);
   }
}
