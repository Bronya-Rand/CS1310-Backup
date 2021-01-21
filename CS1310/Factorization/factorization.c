/* C program by Azariel Del Carmen for CS1310 Oct 2020
 * Get 2 positive integers and operate the factors,
 * prime factorization, GCF and LCM
 * ||||||||||||||||||||||||\_|||__|||||||||
 * |||||||||||||||||||S\_\@\_||___|||||||||
 * |||||||||||||||||SS@S\\SS__\__||||||||||
 * ||||||||||||||||S@@@@\_\S_\S_|||||||||||
 * ||||||||||||||\S@@SSSSSSSSSSSS\|||||||||
 * |||||||||||||\S@SSSSSSSSSS@S@@@SS|||||||
 * |||||||||||||S@SS@@@@@@@@@@@SSS@@S||||||
 * ||||||||||||SSSS@@@@@@@@@@@SSSSS@S\|||||
 * |||||||||||SSSSS@@@@@@@@@@SSSSSSSS\|||||
 * |||||||||||SSS@@@@@@@@@@@SSSSSSSS@S|||||
 * ||||||||||SSS@@@@@@@@@@@SSS@SSS@@@S\||||
 * ||||||||||SS@@@@@@@@@@SSSS@@\S@@@@@S_|||
 * |||||||||SS@@@@@@@@@@SSS@@@SSS@@@@SS\|||
 * ||||||||_S@@@@@@@@@SSSS@@S\\S@@@@SSS\|||
 * ||||||||SS@@@@@@SSSSS@@SS\\S@@@@@S\S\_||
 * |||||||SSS@SSSSSSSSSSS\\\SSS@@@@@S\@S_||
 * ||||||S@SSSS\SSSSS\\\\\S@@SS@@@@@S\@S_||
 * |||||S@@S\\\\\\\\\\SSSS@@@@S@@@@SS\S\|||
 * ||||S@@@S\__\___SS@@@@SSSSSSS@@@S\\S\|||
 * ||||S@@@S\\S\_\S@@@@@@SSSS@SS@@@S\\S\|||
 * |||\S@@SSSSSSSS@@@@@@@\||_\SSS@S\\\S\|||
 * |||\SSS\SSSSSS@@@@@@@@\__\__SSSS\\SS_|||
 * |||_SS\\SSSSSSSS@S@@@@S\\\@_\SS\\\S\||||
 * |||\S@@SSSSSSSSSSSSSSSSSSSSS@\\\\\S\||||
 * ||S@@@@SSS@SSS@SS@SSSSSSSSS@S\\\\\\_||||
 * |S@@@@@S\\@@@@@SS@@SSSSSSS@S\\\\\\_|||||
 * |S@@@@S@\\S@@@@@@@@@@SSSSSS\\\SSS\||||||
 * \S@@@SSS_\S@@@S@@@@@@@@SSS\\\SSS\_||||||
 * S@@@SSSS_S@S@@@SS@@@@@@S\\\SSSS\||||||||
 * S@SSSSS@S@@SS@@@@@@@@@S\\\\\\\\_||||||||
 * SSSSSSS@@@@@SS@@@@@SS\\__\\\\\_|||||||||
 * @@@@@SS@@@@@@SSSSS\\\__||_\_||||||||||||
 * @@@SSSSS@@@@@S\\\\\\__|||||||||||||||||| 
 */
 
#include <stdio.h>

/* obtains the integer the user inputs */
int getValue (void)
{
	int temp = 0; /* gets the user's value */
	
	while(temp <= 0)
	{ /* asks for a positive integer */
		printf("Please type a positive integer: ");
		scanf("%d", &temp);
	}
	printf("\nYou typed in %d.\n", temp); /* returns their inputted value */
	return temp; /* returns value to variable */
}

/* obtains the factors that goes to a given value */
int factor (int value)
{
	int i = 0; /* holds factors up to what value holds */
	printf("\nThe factors of %d are: ", value);
	for (i = 1; i <= value; i++){ /* checks each position if the remainder equals 0 */
		if (value % i == 0)
		{
			printf(" %d ", i); /* prints the factors of the value */
		}
	}
}

/* obtains the GCF of both values */
int gcf(int valueA, int valueB)
{
	int num = valueA; /* holds valueA as num for GCF */
	while(valueA%num != 0 || valueB%num != 0)
	{ /* checks each position if the remainder does not equal 0 */
		num = num - 1; /* subtracts num by 1 if it has a remainder */
	}
	printf("\nThe GCF of your values is: %d", num);
}

/* obtains the LCM of both values */
int lcm(int valueA, int valueB)
{
	int num = valueA; /* holds valueA as num for GCF */
	while(num%valueA != 0 || num%valueB != 0)
	{ /* checks each position if the remainder does not equal 0 */
		num = num + 1; /* adds num by 1 if it has a remainder */
	}
	printf("\nThe LCM of your values is: %d", num);
}

/* checks prime factorization (by Dr. Redfield) */
int prime (int num)
{
	int count = 1;
	printf("\nThe prime factorizations of %d is: ", num);
	while(count < num)
	{
		count = count + 1;
		if (num%count == 0)
		{
			printf(" %d ", count);
			num = num/count;
			count = count - 1; 
		}
	}
}

void main (void)
{
	int valA, valB = 0; /* stores the user's values */
	char cont = 'n'; /* stores user input to continue loop */
	printf("This program takes 2 positive integers and returns\n the factors, prime factor, GCF and LCM of them.\n\n");
	do /* restart/start code to start factorization */
	{
		valA = getValue(); /* get 1st value */
		valB = getValue(); /* get 2nd value */
		factor(valA); /* factor 1st value */
		factor(valB); /* factor 2nd value */
		prime(valA); /* prime factor 1st value */
		prime(valB); /* prime factor 2nd value */
		gcf(valA, valB); /* get gcf of both values */
		lcm(valA, valB); /* get lcm of both values */
		printf("\n\nDo you want to try again? Y/N: "); /* asks if they want to try again */
		scanf(" %c", &cont);
	}
	while (cont == 'y' || cont == 'Y'); /* make sure continue happens with y or Y */
}
