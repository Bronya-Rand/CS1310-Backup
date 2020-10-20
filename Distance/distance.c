/* C program by Azariel Del Carmen for CS1310
 * Calculate distance with given rate and time
 */

#include <stdio.h>

void main(void){
    double rate, time, distance; // holds rate (mpg), time (hrs) and distance (mph)
    printf("This program calculates the distance you will go. \n");
    rate = 75;
    time = 23;
    distance = rate * time;

    printf("You went %.21lf miles at %.11lf mph for %.11lf hours. \n\n",
    distance, rate, time);
}

/*
@@@@@@@@@@%;%#%S@@@@
@@@@@@@@;:**?%S#@@@@
@@@@@@@;::;*+;*?@@@@
@@@@@@;;;;;;::::;@@@
@@@@@@;:::::::;:;*@@
@@@@@;;::::::;;;;*@@
@@@@@;::::::;:+;:;S@
@@@@+;::::;;:;+::;?@
@@@@;::::;:;+*::;+*@
@@@;;;;;;;+*+;::;;+@
@@;:+**?**+;:;::+++@
@?::+?%?;::;;;;:++*@
@+;;;;+;:::%%*;;*+?@
@*;+;;;::::*??++**%@
@;:;;;;;;;;;;;+?**@@
;::;*;:;;:;;;;?**?@@
;::;?;:::::;;*+;?@@@
;:;;+;:;;::;*++*#@@@
;:;;::;::;+?%??%@@@@
::;;::;+*?%###@@@@@@
*/