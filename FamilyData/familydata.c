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

#include <stdio.h>
#include <string.h>
#include <time.h>

struct family
{
	char name[50];
	char street[50];
	char csz[50];
	char relation[50];
	char birthday[30];
};
struct family people[7];

void birthday(FILE *out, int bmonth, int bday, int byear)
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
			fprintf(out, "Birthday: Unknown Month %d, %d\n", bday, byear);
			break;
	}
}

char age(FILE *out, int bmonth, int bday, int byear)
{
	int cmonth, cday, cyear, tempVal;
	
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	cday = local->tm_mday;			// get day of month (1 to 31)
	cmonth = local->tm_mon + 1;   	// get month of year (0 to 11)
	cyear = local->tm_year + 1900;	// get year since 1900
	tempVal = cyear-byear;
	if(bmonth > cmonth && bmonth <= 12)
	{
		fprintf(out, "Age: %d\n\n", tempVal);
	}
	else if (bmonth == cmonth && bday >= cday && bday <= 31)
	{
		fprintf(out, "Age: %d\n\n", tempVal);
	}
	else if (bmonth <= 12 && bday <= 31 && byear <= cyear)
	{
		tempVal--;
		fprintf(out, "Age: %d\n\n", tempVal);
	}
	else
	{
		fprintf(out, "Age: Unknown");
	}
}
void main(void)
{
	FILE *in, *out;
	char astring[80];
	int num, month, day, year;
	
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	printf("In");
	for(num = 0; num < 3; num++)
	{
		strcpy(people[num].name, fgets(astring, 80, in));
		strcpy(people[num].street, fgets(astring, 80, in));
		strcpy(people[num].csz, fgets(astring, 80, in));
		strcpy(people[num].relation, fgets(astring, 80, in));
		strcpy(people[num].birthday, fgets(astring, 80, in));
	}
	for(num = 0; num < 3; num++)
	{
		printf("Out");
		fprintf(out, "%s ", strtok(people[num].name, "\n"));
		fprintf(out, "Relation: %s\n", strtok(people[num].relation, "\n"));
		fprintf(out, "%s ", strtok(people[num].street, "\n"));
		month = atoi(strtok(people[num].birthday, "-"));
		day = atoi(strtok(NULL, "-"));
		year = atoi(strtok(NULL, " "));
		birthday(out, month, day, year);
		fprintf(out, "%s ", strtok(people[num].csz, "\n"));
		age(out, month, day, year);
	}
	fclose(in);
	fclose(out);
}
