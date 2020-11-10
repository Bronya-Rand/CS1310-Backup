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
		fprintf(out, "%s\n", people[num].birthday);
		fprintf(out, "%s\n", people[num].csz);
	}
	fclose(in);
	fclose(out);
}
