/* ==========================================================================
   Troubleshooting Practice #2
   Description:  This program calculates a person's Body Mass Index (BMI) in
   pounds using the formula:  
             BMI = ( weightInPounds X 703 ) / (heightInInches^2)
             
       Author:  Scott Raymond
         Date:  29 Aug 2020
	 Language:  C 
    For Class:  CS1310, Programming I 
===========================================================================*/
#include <stdio.h>

void main(void)
{
	double weight;      /* holds the user's weight in pounds */
	double height;      /* holds the user's height in inches */
	double BMI;         /* holds the user's BMI              */
	
	printf("This program will calculate BMI in pounds.\n\n");
	
	printf("Enter the person's weight in pounds: ");
	scanf("%lf", &weight);
	printf("Enter the person's height in inches: ");
	scanf("%lf", &height);
	printf("You entered a person who is %.1lf inches tall and weighs "
	       "%.1lf pounds.", height, weight);
	
	/* calculate BMI based on formula in description */       
	BMI = (weight * 703) / (height * height);
	
	printf("\n\nThe person's BMI is: %.2lf", BMI);
	printf("\nHe/she is considered: ");
	if (BMI < 18.5)                /* if the person is underweight */
	{
		printf("Underweight.\n");
	}
	else if (BMI >= 18.5 && BMI <= 24.9) /* if the person is normal      */
	{
		printf("Normal.\n");
	}
	else if (BMI >= 25 && BMI <= 29.9)   /* if the person is overweight  */
	{
		printf("Overweight.\n");
	}
	else                /* if the person is obese       */
	{
		printf("Obese.\n");
	}
}
