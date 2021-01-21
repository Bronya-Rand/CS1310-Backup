/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * Purpose: Get 5 numbers into an array and average
 * them
 */
#include <stdio.h>

void main (void){
	double nums[5], /* holds user input */
		temp, sum; /* to read in one value */
	int index; /* place into the array */
	double min, max; /* to find min/max values in array */
	
	printf("If you give me five numbers, I will tell you the average.\n\n");
	
	for(index = 0; index < 5; index++){ /* gets 5 numbers */
		printf("Please type in a number:  ");
		scanf("%lf", &temp); /* or &nums[index] */
		nums[index] = temp;
		printf("You entered %.3lf. \n", nums[index]);
	}
	
	/* calculate and print average */
	sum = 0;
	for(index = 0; index < 5; index++){ /* to add each element to sum */
		sum = sum + nums[index];
	}
	printf("\nThe total sum of your total numbers is %lf. \n", sum);
	printf("and the average is %lf.\n\n", sum/5);
	
	/* find min and max inputs */
	min = nums[0];
	max = nums[0];
	for(index = 1; index < 5; index++){ /* find min and max value of array */
		if (max < nums[index]){
			max = nums[index];
		}
		if (min > nums[index]){
			min = nums[index];
		}
	}
	printf("The min of your values is %.3lf and the max is %.3lf.", min, max);
}
