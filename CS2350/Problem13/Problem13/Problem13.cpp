//----------------------------------------------------
// Dr. Art Hanna
// Problem #13 Driver program
// Problem13.cpp
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Define application-specific STATE strings
#define ONSTRING  "1"
#define OFFSTRING "0"
#define UNKSTRING "?"

#include ".\SDLS.h"

CIRCUIT circuit;

//----------------------------------------------------
int main()
//----------------------------------------------------
{
    void TestCircuit(STATE D, STATE B3, STATE B2, STATE B1, STATE B0);

    try
    {
        char B[6 + 1];

        circuit.Load("Problem13");

        printf("XXXX [0000-1111]? ");
        while (gets_s(B))
        {
            printf("\n");
            if (strcmp(B, "0000") == 0)
            {
                printf("Test 0000 = '0'\n");
                TestCircuit(OFF, OFF, OFF, OFF, OFF);
                TestCircuit(ON, OFF, OFF, OFF, OFF);
            }
            else if (strcmp(B, "0001") == 0)
            {
                printf("Test 0001 = '1'\n");
                TestCircuit(OFF, OFF, OFF, OFF, ON);
                TestCircuit(ON, OFF, OFF, OFF, ON);
            }
            else if (strcmp(B, "0010") == 0)
            {
                printf("Test 0010 = '2'\n");
                TestCircuit(OFF, OFF, OFF, ON, OFF);
                TestCircuit(ON, OFF, OFF, ON, OFF);
            }
            else if (strcmp(B, "0011") == 0)
            {
                printf("Test 0011 = '3'\n");
                TestCircuit(OFF, OFF, OFF, ON, ON);
                TestCircuit(ON, OFF, OFF, ON, ON);
            }
            else if (strcmp(B, "0100") == 0)
            {
                printf("Test 0100 = '4'\n");
                TestCircuit(OFF, OFF, ON, OFF, OFF);
                TestCircuit(ON, OFF, ON, OFF, OFF);
            }
            else if (strcmp(B, "0101") == 0)
            {
                printf("Test 0101 = '5'\n");
                TestCircuit(OFF, OFF, ON, OFF, ON);
                TestCircuit(ON, OFF, ON, OFF, ON);
            }
            else if (strcmp(B, "0110") == 0)
            {
                printf("Test 0110 = '6'\n");
                TestCircuit(OFF, OFF, ON, ON, OFF);
                TestCircuit(ON, OFF, ON, ON, OFF);
            }
            else if (strcmp(B, "0111") == 0)
            {
                printf("Test 0111 = '7'\n");
                TestCircuit(OFF, OFF, ON, ON, ON);
                TestCircuit(ON, OFF, ON, ON, ON);
            }
            else if (strcmp(B, "1000") == 0)
            {
                printf("Test 1000 = '8'\n");
                TestCircuit(OFF, ON, OFF, OFF, OFF);
                TestCircuit(ON, ON, OFF, OFF, OFF);
            }
            else if (strcmp(B, "1001") == 0)
            {
                printf("Test 1001 = '9'\n");
                TestCircuit(OFF, ON, OFF, OFF, ON);
                TestCircuit(ON, ON, OFF, OFF, ON);
            }
            else if (strcmp(B, "1010") == 0)
            {
                printf("Test 1010 = 'a'\n");
                TestCircuit(OFF, ON, OFF, ON, OFF);
                TestCircuit(ON, ON, OFF, ON, OFF);
            }
            else if (strcmp(B, "1011") == 0)
            {
                printf("Test 1011 = 'b'\n");
                TestCircuit(OFF, ON, OFF, ON, ON);
                TestCircuit(ON, ON, OFF, ON, ON);
            }
            else if (strcmp(B, "1100") == 0)
            {
                printf("Test 1100 = 'c'\n");
                TestCircuit(OFF, ON, ON, OFF, OFF);
                TestCircuit(ON, ON, ON, OFF, OFF);
            }
            else if (strcmp(B, "1101") == 0)
            {
                printf("Test 1101 = 'd'\n");
                TestCircuit(OFF, ON, ON, OFF, ON);
                TestCircuit(ON, ON, ON, OFF, ON);
            }
            else if (strcmp(B, "1110") == 0)
            {
                printf("Test 1110 = 'e'\n");
                TestCircuit(OFF, ON, ON, ON, OFF);
                TestCircuit(ON, ON, ON, ON, OFF);
            }
            else if (strcmp(B, "1111") == 0)
            {
                printf("Test 1111 = 'f'\n");
                TestCircuit(OFF, ON, ON, ON, ON);
                TestCircuit(ON, ON, ON, ON, ON);
            }
            else
                printf("Not in 0000-1111. Try again!\n");
            printf("\nXXXX [0000-1111]? ");
        }
    }
    catch (SDLSEXCEPTION& exception)
    {
        printf("Exception: %s\n", exception.GetErrorMessage());
    }

    system("PAUSE");
    return(0);
}

//----------------------------------------------------
void TestCircuit(STATE D, STATE B3, STATE B2, STATE B1, STATE B0)
//----------------------------------------------------
{
    char LED[9 + 1][5 + 1];

    circuit.SetIN("D", D);
    circuit.SetIN("CK", ON);
    circuit.SimulateLogic();
    circuit.SetIN("CK", OFF);
    circuit.SetIN("B3", B3);
    circuit.SetIN("B2", B2);
    circuit.SetIN("B1", B1);
    circuit.SetIN("B0", B0);
    circuit.SimulateLogic();

    printf("\nSEG1-SEG7 = %s%s%s%s%s%s%s\n\n",
        StateString(circuit.GetOUT("SEG1")),
        StateString(circuit.GetOUT("SEG2")),
        StateString(circuit.GetOUT("SEG3")),
        StateString(circuit.GetOUT("SEG4")),
        StateString(circuit.GetOUT("SEG5")),
        StateString(circuit.GetOUT("SEG6")),
        StateString(circuit.GetOUT("SEG7")));

    for (int r = 1; r <= 9; r++)
        for (int c = 1; c <= 5; c++)
            LED[r][c] = ' ';

    if (circuit.GetOUT("SEG1") == ON)
    {
        LED[5][1] = '*';
        LED[6][1] = '*';
        LED[7][1] = '*';
        LED[8][1] = '*';
        LED[9][1] = '*';
    }
    if (circuit.GetOUT("SEG2") == ON)
    {
        LED[1][1] = '*';
        LED[2][1] = '*';
        LED[3][1] = '*';
        LED[4][1] = '*';
        LED[5][1] = '*';
    }
    if (circuit.GetOUT("SEG3") == ON)
    {
        LED[1][1] = '*';
        LED[1][2] = '*';
        LED[1][3] = '*';
        LED[1][4] = '*';
        LED[1][5] = '*';
    }
    if (circuit.GetOUT("SEG4") == ON)
    {
        LED[1][5] = '*';
        LED[2][5] = '*';
        LED[3][5] = '*';
        LED[4][5] = '*';
        LED[5][5] = '*';
    }
    if (circuit.GetOUT("SEG5") == ON)
    {
        LED[5][5] = '*';
        LED[6][5] = '*';
        LED[7][5] = '*';
        LED[8][5] = '*';
        LED[9][5] = '*';
    }
    if (circuit.GetOUT("SEG6") == ON)
    {
        LED[9][1] = '*';
        LED[9][2] = '*';
        LED[9][3] = '*';
        LED[9][4] = '*';
        LED[9][5] = '*';
    }
    if (circuit.GetOUT("SEG7") == ON)
    {
        LED[5][1] = '*';
        LED[5][2] = '*';
        LED[5][3] = '*';
        LED[5][4] = '*';
        LED[5][5] = '*';
    }

    printf("\"showHexDigits\" latch is %s\n", ((D == ON) ? " ON" : "OFF"));
    for (int r = 1; r <= 9; r++)
    {
        for (int c = 1; c <= 5; c++)
            printf("%c", LED[r][c]);
        printf("\n");
    }
}
