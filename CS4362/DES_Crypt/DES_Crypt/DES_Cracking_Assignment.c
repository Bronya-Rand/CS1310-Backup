#include <stdio.h>
#include "DES.h"
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

// Loading data from a text file
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

void printText(unsigned char hash[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%c", hash[i]);
    printf("\n");
}

void getBlock(unsigned char cipherText[], unsigned char cipherBlock[], int i)
{
    for (int b = 0; b < 8; b++)
    {
        cipherBlock[b] = cipherText[(8*i)+b];
    }
}

int main()
{
    uchar key[8], // You need to get that key using brute force attack
        plainTextBlock[8],
        cipherTextBlock[8],
        schedule[16][6];
    uint state[2];

    // Start you work.................
    uchar cipherText[32];
    loadFile(cipherText, 32);
    printf("Encrypted: ");
    printText(cipherText, 32);
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
                                    key[0] = a;
                                    key[1] = b;
                                    key[2] = c;
                                    key[3] = d;
                                    key[4] = e;
                                    key[5] = f;
                                    key[6] = g;
                                    key[7] = h;

                                    uchar plainText[32];
                                    int i;

                                    for (i = 0; i < 4; i++)
                                    {
                                        key_schedule(key, schedule, DECRYPT);
                                        getBlock(cipherText, cipherTextBlock, i);
                                        des_crypt(cipherTextBlock, plainTextBlock, schedule);
                                        for (int j = 0; j < 8; j++)
                                        {
                                            plainText[(8*i)+j] = plainTextBlock[j];
                                        }
                                    }

                                    bool isAZ = true;
                                    for (i = 0; i < 32; i++)
                                    {
                                        if (!isalpha(plainText[i]) && plainText[i] != ' ')
                                        {
                                            isAZ = false;
                                        }
                                    }

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
