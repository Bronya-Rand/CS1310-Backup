/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * Outputs the area of a triangle given 3 valid sizes
 * 
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
#include <math.h>

void main(void)
{
	/* initializes variables */
	double sideA, sideB, sideC = 0;
	double s, totalArea;
	
	/* makes a sample triangle */
	printf("                                 ^ \n");
	printf("                                / \\ \n");
	printf("                               /   \\ \n");
	printf("                              /     \\ \n");
	printf("                              ------- \n\n");
	
	/* purpose of the program */
	printf("This program makes a triangle given 3 lengths and if it's valid.\n\n");
	
	/* Ask for Lengths */
	printf("Please provide Side A's length: ");
	scanf("%lf", &sideA);
	printf("You inputted %lf for Side A.\n", sideA);
	printf("Please provide Side B's length: ");
	scanf("%lf", &sideB);
	printf("You inputted %lf for Side B.\n", sideB);
	printf("Please provide Side C's length: ");
	scanf("%lf", &sideC);
	printf("You inputted %lf for Side C.\n", sideC);

	/* checks if the lengths are less than 0 */
	if (sideA < 0 || sideB < 0 || sideC < 0)
	{
		printf("The inputs given must be greater than 0.");
	}
	/* checks if all sides are bigger than 2 added sides */
	else if (sideA > sideB + sideC || sideB > sideA + sideC || sideC > sideA + sideB)
	{
		printf("The inputs given do not make a valid triangle.");
	}
	/* calculate s and totalArea and output it */
	else
	{
		printf("The inputs given make a valid triangle.\n\n");
		s = 0.5 * (sideA + sideB + sideC);
		totalArea = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
		printf("The total area for your triangle is %lf.\n\n", totalArea);
	}
}
