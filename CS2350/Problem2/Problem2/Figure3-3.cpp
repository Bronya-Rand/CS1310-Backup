//----------------------------------------------------
// Dr. Art Hanna
// Figure 3-3 (2-input version)
// Figure3-3.cpp
//----------------------------------------------------

// Use default STATE strings " ON", "OFF", and "UNK"

#include ".\SDLS.h"

//----------------------------------------------------
int main()
//----------------------------------------------------
{
    /*
       A    B    M
    ---- ---- ----
     XXX  XXX  XXX
    */
    try
    {
        CIRCUIT circuit;

        circuit.Load("Figure3-3");
        printf("   A    B    M\n");
        printf("---- ---- ----\n");
        for (STATE A = OFF; A >= ON; A = Predecessor(A))
            for (STATE IN2 = OFF; IN2 >= ON; IN2 = Predecessor(IN2))
            {
                circuit.SetIN("A", A);

                // Two ways to set IN#2
                circuit.SetIN(2, IN2);
                circuit.SetIN("B", IN2);
                circuit.SimulateLogic();
                printf(" %3s  %3s  %3s\n",
                       StateString(A), StateString(IN2),
                       StateString(circuit.GetOUT("M"))
                       // OR...     StateString(circuit.GetOUT(1))
                );
            }
    }
    catch (SDLSEXCEPTION &exception)
    {
        printf("Exception: %s\n", exception.GetErrorMessage());
    }

    system("PAUSE");
    return (0);
}
