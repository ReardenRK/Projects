#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 1)
    {
        printf("Only one key is accepted.");
    }
    string key = argv[1];
    char checkkey[strlen(key)];
    printf("%s",key);

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("Invalid key\nKey must only contain alphabets.");
            return 1;
        }
        checkkey[i] = key[i];
    }
    string plaintext = get_string("plaintext: ");
}