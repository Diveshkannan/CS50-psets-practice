#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int j = 0, length = strlen(argv[1]); j < length; j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Key should contain integers\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    if (key <= 0)
    {
        printf("Key should be greater than 0\n");
        return 1;
    }
    int k = key % 26;

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {

        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'A') + (k)) % 26) + 'A');
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'a') + (k)) % 26) + 'a');
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
