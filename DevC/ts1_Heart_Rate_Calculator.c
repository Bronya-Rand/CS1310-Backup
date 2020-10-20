/* ==========================================================================
   Troubleshooting Practice #1
   Description:  This program calculates a person's target exercise heart
   rate range:     min = 50% of max heart rate  
                   max = 85% of max heart rate
                   max heart rate = 220 - age
    NOTE:  even though percentages typically have decimal places the program
	uses integers as heart beats are normally referred to in whole numbers.
	         
       Author:  Scott Raymond
         Date:  29 Aug 2020
	 Language:  C 
    For Class:  CS1310, Programming I 
===========================================================================*/
#include <stdio.h>
#define MAXBEATS 220    /* max beats per minute */

void main(void)
{
	int age;              /* the person's age                  */
	int min;              /* lower end of heart rate range     */
	int max;              /* upper end of heart rate range     */
	int maxHeartRate;     /* the person's max heart rate       */
	
	printf("This program will calculate a person's target, exercise"
	       ", heart rate range.\n\n");
	
	printf("Enter the person's age (rounded to the nearest year): ");
	scanf("%d", &age);
	printf("You entered an age of: %d.", age);
	
	/* calculate maxHeartRate and the min and max target rates */       
	maxHeartRate = MAXBEATS - age;
	min = maxHeartRate * .50;
	max = maxHeartRate * .85;
	
	printf("\n\nThe person's ideal heart rate range, while exercising, "
	       "is from %d to %d beats per minute.\n\n", min, max);
	
}
