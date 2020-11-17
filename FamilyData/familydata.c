/* C program by Azariel Del Carmen for CS1310 Nov 2020
 * This program takes family data from in.txt and outputs it
 * to out.txt in a formatted output.
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

/* standard i/o library */
#include <stdio.h> 
/* string library */
#include <string.h> 
/* I don't know if this is allowed but library that grabs current time for age. */
#include <time.h>


/* structure for family information */
struct family 
{
	char name[50];
	char street[50];
	char csz[50];
	char relation[50];
	char birthday[30];
};
/* structure for family information with 7 people*/
struct family people[7]; 

/* function responsible for converting 05-13-1997 to May 13, 1997 */
void birthday(FILE *out, int bmonth, int bday, int byear) 
/* uses FILE *out to print to out.txt, and bmonth, bday, and byear as ints */
{
	switch(bmonth){
		case 1:
			fprintf(out, "Birthday: January %d, %d\n", bday, byear);
			break; 
		case 2:
			fprintf(out, "Birthday: Feburary %d, %d\n", bday, byear);
			break; 
		case 3:
			fprintf(out, "Birthday: March %d, %d\n", bday, byear);
			break; 
		case 4:
			fprintf(out, "Birthday: April %d, %d\n", bday, byear);
			break; 
		case 5:
			fprintf(out, "Birthday: May %d, %d\n", bday, byear);
			break;
		case 6:
			fprintf(out, "Birthday: June %d, %d\n", bday, byear);
			break; 
		case 7:
			fprintf(out, "Birthday: July %d, %d\n", bday, byear);
			break; 
		case 8:
			fprintf(out, "Birthday: August %d, %d\n", bday, byear);
			break; 
		case 9:
			fprintf(out, "Birthday: September %d, %d\n", bday, byear);
			break; 
		case 10:
			fprintf(out, "Birthday: October %d, %d\n", bday, byear);
			break; 
		case 11:
			fprintf(out, "Birthday: November %d, %d\n", bday, byear);
			break; 
		case 12:
			fprintf(out, "Birthday: December %d, %d\n", bday, byear);
			break; 
		default:
			/* normally this will be a error but giving it Unknown Month is funnier IMO*/
			fprintf(out, "Birthday: Unknown Month %d, %d\n", bday, byear);
			break;
	}
}

/* function responsible for getting age using time library */
char age(FILE *out, int bmonth, int bday, int byear)
/* uses FILE *out to print to out.txt, and bmonth, bday, and byear as ints */
{
	/* initializes cmonth, cday, cyear, and ageVal as not assigned ints */
	int cmonth, cday, cyear, ageVal; 
	
	/* grabs current time using time_t as a type and assigns it to now */
	time_t now; 
	/* prints time using time_t now and assigns it to now */
	time(&now);  
	/* sets structure tm in time using localtime(time_t now) and assigns it to now */
	struct tm *local = localtime(&now);
	/* grabs day of month */
	cday = local->tm_mday; 
	/* grabs month from January (1) to December (12) */
	cmonth = local->tm_mon + 1; 
	/* grabs years after 1900 and adds 1900 to it for current year */
	cyear = local->tm_year + 1900;
	/* subtracts current year with birthday year */	
	ageVal = cyear-byear;
	/* checks if month is past or is birthday month and day is past 
	or is birthday day and birthday month, day and age is valid */
	if (cmonth >= bmonth && cday >= bday && bmonth <= 12 && bday <= 31 && byear <= cyear && ageVal >= 0)
	{
		/* print the age with no changes to out.txt */
		fprintf(out, "Age: %d\n\n", ageVal);
	}
	/* checks if month is before or is birthday month and day is before 
	birthday day and birthday month, day and age is valid */
	else if (cmonth <= bmonth && cday < bday && bmonth <= 12 && bday <= 31 && byear <= cyear && ageVal >= 0)
	{
		/* subtract ageVal by 1 as no birthday */
		ageVal--;
		/* if ageVal is not a negative */
		if (ageVal >= 0)
		{
			/* print the age with no changes to out.txt */
			fprintf(out, "Age: %d\n\n", ageVal);
		}
		else
		{
			/* print age is unknown to out.txt */
			fprintf(out, "Age: Unknown");
		}
		
	}
	else
	{
		/* print the age is unknown to out.txt */
		fprintf(out, "Age: Unknown\n\n");
	}
}

void main(void)
{
	/* initializes in and out as file variables */
	FILE *in, *out; 
	/* initializes a temp char to hold input to struct */
	char astring[80]; 
	/* initializes num, month, day and year as non assigned ints */
	int num, month, day, year; 
	
	/* opens in.txt in read mode to in */
	in = fopen("in.txt", "r"); 
	/* opens in.txt in write mode to out */
	out = fopen("out.txt", "w"); 
	printf("Reading data. Please wait...\n\n");
	/* assigns each line section of in.txt to a struct variable */
	for(num = 0; num < 7; num++)
	{
		strcpy(people[num].name, fgets(astring, 80, in));
		strcpy(people[num].street, fgets(astring, 80, in));
		strcpy(people[num].csz, fgets(astring, 80, in));
		strcpy(people[num].relation, fgets(astring, 80, in));
		strcpy(people[num].birthday, fgets(astring, 80, in));
	}
	printf("Formatting and printing out data. Please wait...");
	/* formats the data to out.txt */
	for(num = 0; num < 7; num++)
	{
		fprintf(out, "%s     ", strtok(people[num].name, "\n"));
		fprintf(out, "Relation: %s\n", strtok(people[num].relation, "\n"));
		fprintf(out, "%s     ", strtok(people[num].street, "\n"));
		/* splits the birthday month, day and year to month, day and year */
		month = atoi(strtok(people[num].birthday, "-"));
		day = atoi(strtok(NULL, "-"));
		year = atoi(strtok(NULL, " "));
		/* gets the formatted birthday from birthday class */
		birthday(out, month, day, year);
		fprintf(out, "%s     ", strtok(people[num].csz, "\n"));
		/* gets the formatted age from birthday class */
		age(out, month, day, year);
	}
	/* closes in and out.txt from read and writing */
	fclose(in);
	fclose(out);
}
