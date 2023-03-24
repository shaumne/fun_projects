#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for valid command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if key is numeric
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert command-line argument to int
    int k = atoi(argv[1]);

    // Prompt user for plaintext input
    printf("plaintext: ");
    char plaintext[1000];
    fgets(plaintext, 1000, stdin);

    // Encrypt plaintext and print ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            printf("%c", (c - base + k) % 26 + base);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
