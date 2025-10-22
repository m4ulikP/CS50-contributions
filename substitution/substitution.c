// This program implements a substitution cipher, where each letter in the plaintext is replaced by a corresponding letter from a provided 26-character key.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cipher(string s, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    int freq[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        char c = tolower(argv[1][i]);
        int index = c - 'a';
        freq[index]++;
        if (freq[index] > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    string pt = get_string("plaintext: ");
    printf("ciphertext: %s\n", cipher(pt, argv[1]));
}

string cipher(string s, string k)
{
    string cip = s;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]))
        {
            int c = s[i] - 'A';
            cip[i] = toupper(k[c]);
        }
        else if (islower(s[i]))
        {
            int c = s[i] - 'a';
            cip[i] = tolower(k[c]);
        }
    }
    return cip;
}
