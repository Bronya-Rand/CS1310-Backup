// DES_Cracking_Assignment.c
// This program cracks DES encrypted files of 32 characters into plaintext.

#include <stdio.h>
#include "DES.h"
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

// Loads the file 'CipherFile.txt' into a variable
// data[]: an array to read the data into
// length: length of data you want to read from the file
// For simplicity, the ciphertext file is containing ONLY 32 characters
void loadFile(unsigned char data[], int length)
{
    FILE *file = fopen("CipherFile.txt", "r");
    if (file)
    {
        int i;
        for (i = 0; i < length; i++)
            data[i] = fgetc(file);

        fclose(file);
    }
    else
        printf("Cannot open the file\n");
}

// Prints out the text one by one with a newline
void printText(unsigned char hash[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%c", hash[i]);
    printf("\n");
}

// splits the 32 character DES text to chunks of 8 depending on i's result
void getBlock(unsigned char cipherText[], unsigned char cipherBlock[], int i)
{
    for (int b = 0; b < 8; b++)
    {
        // multiply 8 and i then add b from this for loop
        // to add 8 characters to a 8 block array no matter
        // the placement in cipherText.
        cipherBlock[b] = cipherText[(8 * i) + b];
    }
}

int main()
{
    uchar key[8],           // You need to get that key using brute force attack
        plainTextBlock[8],  // array block of readable letters
        cipherTextBlock[8], // array block of cipher letters
        schedule[16][6];
    uint state[2];

    // Start you work.................
    // add a variable to store the DES text
    uchar cipherText[32];

    // load and print the DES text out for original input
    loadFile(cipherText, 32);
    printf("Encrypted: ");
    printText(cipherText, 32);

    // start a nested for-loop of eight!
    printf("\nProcessing...");
    for (int a = 0; a <= 255; a++)
    {
        for (int b = 0; b <= 255; b++)
        {
            for (int c = 0; c <= 255; c++)
            {
                for (int d = 0; d <= 255; d++)
                {
                    for (int e = 0; e <= 255; e++)
                    {
                        for (int f = 0; f <= 255; f++)
                        {
                            for (int g = 0; g <= 255; g++)
                            {
                                for (int h = 0; h <= 255; h++)
                                {
                                    // set every key space to a-h values in the for-loop
                                    key[0] = a;
                                    key[1] = b;
                                    key[2] = c;
                                    key[3] = d;
                                    key[4] = e;
                                    key[5] = f;
                                    key[6] = g;
                                    key[7] = h;

                                    // set a variable to store plaintext of 32
                                    // set a variable for the chunk for-loop
                                    uchar plainText[32];
                                    int i;

                                    // lets start decrypting by chunks
                                    for (i = 0; i < 4; i++)
                                    {
                                        key_schedule(key, schedule, DECRYPT);

                                        // split to chunks via i's value
                                        getBlock(cipherText, cipherTextBlock, i);
                                        des_crypt(cipherTextBlock, plainTextBlock, schedule);

                                        // add the decrypted text to plainText
                                        for (int j = 0; j < 8; j++)
                                        {
                                            plainText[(8 * i) + j] = plainTextBlock[j];
                                        }
                                    }

                                    // check if we do indeed have a variable of only A-Z and spaces
                                    bool isAZ = true;
                                    for (i = 0; i < 32; i++)
                                    {
                                        if (!isalpha(plainText[i]) && plainText[i] != ' ')
                                        {
                                            isAZ = false;
                                        }
                                    }

                                    // if 'isAZ' is still true, exit the program with the result
                                    if (isAZ)
                                    {
                                        printf("Decrypted!\nDecrypted: ");
                                        printText(plainText, 32);
                                        getchar();
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    getchar();
    return 0;
}
