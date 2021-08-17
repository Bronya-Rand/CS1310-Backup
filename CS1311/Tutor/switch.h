/* C program by Azariel Del Carmen for CS1311 Apr 2021
 * This header program describes the switch.h header file
 *
 * ||||||SSS\\\\\\\\SS||
 * ||||SS\\`````````\S||
 * ||SS\````````````\SS|
 * |SS\``````````````\SS
 * |S\\\\\\\\\\\``````\S
 * S\\SSSSSSSSS\SSS\```S
 * S\SSSSSSSSS\\SSSS\``\
 * \\SSS\SSS\\SS\SSS\``\
 * \\S\\\\\\\SS\\\SSS``\
 * \\S\\\`\SSSS`__\SS`\S
 * S\S\\\\SSSSS\\\\\\`\S
 * S\\\\\\SSSSSS\\\\`\S|
 * SSS\\\\S\\SSS\\\\SS||
 * |SSS\\\\\\\\\\``SS|||
 * ||||SS\_____\\``SS|||
 * |||||S`|\\`|\S\`SS|||
 * |||||S_|``_|`S\`\S|||
 * ||||S\`\SS\``S\\SS|||
 * ||SS\\\\\S\\``SSS||||
 * ||S\_|`\\\\\_`S||||||
 * ||SS\__``|_\`SS||||||
 * |||SSSS``\\`\S|||||||
 * ||||||S\`\S\\S|||||||
 * ||||||SS\SSS\S|||||||
 */
 
#include <stdio.h>

void SwitchCase(void)
{
	char showExample = 'n'; /* stores user's input */
	
	printf("*** Switch *** \n");
	printf("The switch statement is a alternative line of code to the if/else statement that executes certain\n");
	printf("lines of codes given the criteria of a variable and the cases in the statement itself which can be either \"integers\" or \"characters\".\n");
	printf("It is normally used to different lines of codes in a simpler if/else statement depending on a variable's\n");
	printf("information than multiple if/else if/else statements for a task. (YandereDev...)\n\n");
	
	/* syntax */
	printf("The syntax of the switch statement is\n\n");
	printf("    switch(variable)\n");
	printf("    {\n");
	printf("        case value:\n");
	printf("            statement\n");
	printf("            break;\n");
	printf("        case value:\n");
	printf("            statement\n");
	printf("            break;\n");
	printf("        default:\n");
	printf("            statement\n");
	printf("            break;\n");
	printf("    }\n\n");
	
	printf("Do you want to see a example of the switch statement? (Y/N): ");
	scanf("%c", &showExample);
	
	if (showExample == 'y' || showExample == 'Y') /* user requests example */
	{
		printf("*** Switch Examples ***\n\n");
		
		/* basic example */
		printf("Here is an example of the switch statement using integers: \n\n");
		printf("    int femaleUniform = 1;\n\n");
		printf("    switch(femaleUniform)\n");
		printf("    {\n");
		printf("        case 1:\n");
		printf("            printf(\"Selected Outfit: School Uniform\");\n");
		printf("            break;\n");
		printf("        default:\n");
		printf("            printf(\"Selected Outfit: Casual Outfit\");\n");
		printf("            break;\n");
		printf("    }\n\n");
		
		printf("The example above shows the switch statement that will execute different parts of the statement depending on \"femaleUniform\".\n\n");
		printf("If the outfit number is 1 the switch statement will execute \"case 1\" and output\n\n");
		printf("    \"Selected Outfit: School Uniform\" \n\nto the console and exit the statement with the line \"break\".\n\n");
		printf("If the name isn't in the switch statement cases, it will execute the \"default\" case and output\n\n");
		printf("    \"Selected Outfit: Casual Uniform\" \n\nto the console and exit the statement with the line \"break\".\n\n");
		
		/* complex example */
		printf("Here is a complex example of the switch statement using chars: \n\n");
		printf("    char student_type = 's';\n\n");
		printf("    printf(\"Type in the student type to list students in that category (Info-Chan: i, Rival: r, Yandere: y): \");\n");
		printf("    scanf(\"%%c\", &student_type);\n");
		printf("    printf(\"You typed in %%c.\", student_type);\n\n");
		printf("    switch(student_type)\n");
		printf("    {\n");
		printf("        case 'i':\n");
		printf("            printf(\"The students categorized as type \"Info-Chan\" are:\\n[Error] Id returned 4 exit status: You don't need to know that information. Focus on your Senpai.\\n\");\n");
		printf("            break;\n");
		printf("        case 'r':\n");
		printf("            printf(\"The students categorized as type \"Rival\" are:\\n        Osana\");\n");
		printf("            break;\n");
		printf("        case 'y':\n");
		printf("            printf(\"The students categorized as type \"Yandere\" are:\\n        Ayano\");\n");
		printf("            break;\n");
		printf("        default:\n");
		printf("            printf(\"Invalid Student Type.\");\n");
		printf("            break;\n");
		printf("    }\n\n");
		
		printf("The example above shows the switch statement that will execute different parts of the statement depending on what the user enters to \"student_type\" via \"scanf\".\n\n");
		printf("If the student type is i, the switch statement will execute \"case i\" and output\n\n");
		printf("    \"The students categorized as type \"Info-Chan\" are:\"\n");
		printf("        [Error] Id returned 4 exit status: You don't need to know that information. Focus on your Senpai. \n\nto the console and exit the statement with the line \"break\".\n\n");
		printf("If the student type is r, the switch statement will execute \"case r\" and output\n\n");
		printf("    \"The students categorized as type \"Rival\" are:\"\n");
		printf("        Osana \n\nto the console and exit the statement with the line \"break\".\n\n");
		printf("If the student type is y, the switch statement will execute \"case y\" and output\n\n");
		printf("    \"The students categorized as type \"Yandere\" are:\"\n");
		printf("        Ayano \n\nto the console and exit the statement with the line \"break\".\n\n");
		printf("If the name isn't in the switch statement cases, it will execute the \"default\" case and output\n\n");
		printf("    \"Invalid Student Type.\" \n\nto the console and exit the statement with the line \"break\".\n\n");
	}
}	