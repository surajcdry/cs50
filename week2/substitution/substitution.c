#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // validate the command-line argument
    // len of command-line arguments == 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // len of key == 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // valid key (only alphabets)
    // no duplicates

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // YTNSHKVEFXRBAUQZCLWDMIPGJO
        // i and j
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key should be all alphabets.\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("No duplicate values allowed.\n");
                return 1;
            }
        }
    }

    string key = argv[1];

    // input from the user (plaintext)
    string plain = get_string("plaintext: ");

    // print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                // encrypt and fix case
                printf("%c", toupper(key[plain[i] - 65]));
            }
            else
            {
                // encrypt and fix case
                printf("%c", tolower(key[plain[i] - 97]));
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
