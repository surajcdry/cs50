#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // validate command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    while (key > 26)
    {
        key -= 26;
    }

    // take input from the user (plaintext)
    string plain = get_string("plaintext: ");

    // print the encrypted text (ciphertext)
    printf("ciphertext: ");
    int temp = 0;

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                // encrypt
                temp = plain[i] + key;
                if (temp > 90)
                {
                    printf("%c", temp - 26);
                }
                else
                {
                    printf("%c", temp);
                }
            }
            else
            {
                // encrypt
                temp = plain[i] + key;
                if (temp > 122)
                {
                    printf("%c", temp - 26);
                }
                else
                {
                    printf("%c", temp);
                }
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
