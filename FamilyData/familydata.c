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

struct family
{
	char name[50];
	char street[50];
	char csz[50];
	char relation[50];
	char birthday[30];
};
struct family people[7];

char birthday(FILE *out, char *bday)
{
	int pbmonth, pbday, pbyear; 
	pbmonth = atoi(strtok(bday, "-"));
	pbday = atoi(strtok(NULL, "-"));
	pbyear = atoi(strtok(NULL, " "));
	
	switch(pbmonth){
		case 1:
			fprintf(out, "January %d, %d", pbday, pbyear);
			break; 
		case 2:
			fprintf(out, "Feburary %d, %d", pbday, pbyear);
			break; 
		case 3:
			fprintf(out, "March %d, %d", pbday, pbyear);
			break; 
		case 4:
			fprintf(out, "April %d, %d", pbday, pbyear);
			break; 
		case 5:
			fprintf(out, "May %d, %d", pbday, pbyear);
			break;
		case 6:
			fprintf(out, "June %d, %d", pbday, pbyear);
			break; 
		case 7:
			fprintf(out, "July %d, %d", pbday, pbyear);
			break; 
		case 8:
			fprintf(out, "August %d, %d", pbday, pbyear);
			break; 
		case 9:
			fprintf(out, "September %d, %d", pbday, pbyear);
			break; 
		case 10:
			fprintf(out, "October %d, %d", pbday, pbyear);
			break; 
		case 11:
			fprintf(out, "November %d, %d", pbday, pbyear);
			break; 
		case 12:
			fprintf(out, "December %d, %d", pbday, pbyear);
			break; 
		default:
			fprintf(out, "Unknown Month %d, %d", pbday, pbyear);
			break;
	}
}

void main(void)
{
	FILE *in, *out;
	char astring[81];
	int num;
	
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	printf("In");
	for(num = 0; num < 2; num++)
	{
		strcpy(people[num].name, fgets(astring, 50, in));
		strcpy(people[num].street, fgets(astring, 50, in));
		strcpy(people[num].csz, fgets(astring, 50, in));
		strcpy(people[num].relation, fgets(astring, 50, in));
		strcpy(people[num].birthday, fgets(astring, 50, in));
	}
	for(num = 0; num < 2; num++)
	{
		printf("Out");
		fprintf(out, "%s\0", people[num].name);
		fprintf(out, "%s\n", people[num].relation);
		fprintf(out, "%s", people[num].street);
		birthday(out, people[num].birthday);
		fprintf(out, "%s\n", people[num].csz);
	}
	fclose(in);
	fclose(out);
}
