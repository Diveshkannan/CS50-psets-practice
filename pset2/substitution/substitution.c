#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void ciphertext(string text, string key);

bool validate_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!validate_key(argv[1]))
    {
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("Plaintext: ");
    ciphertext(plaintext, key);
    return 0;
}

void ciphertext(string plaintext, string key)
{
    int index = 0;

    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            index = toupper(plaintext[i]) - 'A';
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(key[index]));
            }
            else
            {
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

bool validate_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return false;
    }

    int index = 0;
    bool array[26];

    for (int q = 0; q < 26; q++)
    {
        array[q] = true;
    }
    for (int j = 0; j < length; j++)
    {
        if (isalpha(key[j]))
        {
            index = toupper(key[j]) - 'A';
            if (!array[index])
            {
                printf("Key must not contain any duplicate characters\n");
                return false;
            }

            array[index] = false;
        }
        else
        {
            printf("Key must contain only alphabets\n");
            return false;
        }
    }
    return true;
}
