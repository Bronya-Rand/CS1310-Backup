//----------------------------------------------------
// Dr. Art Hanna
// Problem #9
// Problem9.cpp
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Define application-specific STATE strings
#define ONSTRING  "1"
#define OFFSTRING "0"
#define UNKSTRING "?"

#include ".\SDLS.h"

FILE* OUTFILE;

//----------------------------------------------------
int main()
//----------------------------------------------------
{
    /*
       A    B  NZP
    ---- ----  ---
    XXXX XXXX  XXX
    */
    try
    {
        CIRCUIT circuit;
        OUTFILE = fopen("Problem9.out", "w");

        circuit.Load("Problem9");
        fprintf(OUTFILE, "   A    B  NZP\n");
        fprintf(OUTFILE, "---- ----  ---\n");
        for (STATE A3 = OFF; A3 >= ON; A3 = Predecessor(A3))
            for (STATE A2 = OFF; A2 >= ON; A2 = Predecessor(A2))
                for (STATE A1 = OFF; A1 >= ON; A1 = Predecessor(A1))
                    for (STATE A0 = OFF; A0 >= ON; A0 = Predecessor(A0))
                        for (STATE B3 = OFF; B3 >= ON; B3 = Predecessor(B3))
                            for (STATE B2 = OFF; B2 >= ON; B2 = Predecessor(B2))
                                for (STATE B1 = OFF; B1 >= ON; B1 = Predecessor(B1))
                                    for (STATE B0 = OFF; B0 >= ON; B0 = Predecessor(B0))
                                    {
                                        circuit.SetIN("A3", A3);
                                        circuit.SetIN("A2", A2);
                                        circuit.SetIN("A1", A1);
                                        circuit.SetIN("A0", A0);
                                        circuit.SetIN("B3", B3);
                                        circuit.SetIN("B2", B2);
                                        circuit.SetIN("B1", B1);
                                        circuit.SetIN("B0", B0);

                                        circuit.SimulateLogic();
                                        fprintf(OUTFILE, "%1s%1s%1s%1s %1s%1s%1s%1s  %1s%1s%1s\n",
                                            StateString(A3), StateString(A2), StateString(A1), StateString(A0),
                                            StateString(B3), StateString(B2), StateString(B1), StateString(B0),
                                            StateString(circuit.GetOUT("N")),
                                            StateString(circuit.GetOUT("Z")),
                                            StateString(circuit.GetOUT("P")));
                                    }
    }
    catch (SDLSEXCEPTION& exception)
    {
        printf("Exception: %s\n", exception.GetErrorMessage());
    }
    fclose(OUTFILE);

    system("PAUSE");
    return(0);
}
