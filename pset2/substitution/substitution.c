#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    string alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (argc < 2) //checks if the key is not provided 
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (argc == 2) // does this if the key is provided
    {
        if (strlen(argv[1]) == 26) //checks if there are exactly 26 characters in the key
        {
            int counter = 0;
            for (int i = 0; i < 25; i++)
            {
                for (int k = i + 1; k <= 25; k++) // iterates through the key and kompares 2 charecters to check if there are any duplicates
                {
                    if (argv[1][i] == argv[1][k]) // 2 characters in the key match - there are duplicates
                    {
                        counter++; 
                    }
                }
            }
            for (int i = 0; i < 26; i++) //iterates through the key to check if all characters are alphabetic
            {
                if (isalpha(argv[1][i]) == false)
                {
                    return 1;
                }
            }
            if (counter < 1) // if there were no duplicates do the following
            {
                string plaintext = get_string("plaintext: ");
                int n = strlen(plaintext);
                char ciphertext[n];
                for (int i = 0; i < n; i++) // iterates through the plaintext
                {
                    for (int a = 0, k = strlen(alphabet); a < k; a++) // iterates through alphabet
                    {
                        char b = plaintext[i];
                        bool space = isspace(b);
                        bool digit = isdigit(b);
                        bool punct = ispunct(b);
                        bool lower = islower(b);
                        bool upper = isupper(b);
                        if (lower == true)
                        {
                            b = toupper(plaintext[i]);
                        }
                        if (alphabet[a] == b) //checks if the character from the plaintext mathces the character in the key, if not - takes the next character of the alphabet
                        {
                            if (upper == true)
                            {
                                char c = toupper(argv[1][a]);
                                ciphertext[i] = c;
                            }
                            else if (lower == true)
                            {
                                char c = tolower(argv[1][a]);
                                ciphertext[i] = c;
                            }
                        }
                        else if (space == true || digit == true || punct == true)
                        {
                            ciphertext[i] = plaintext[i];
                        }
                    }
                }
                printf("ciphertext: ");
                for (int i = 0; i < n; i++)
                {
                    printf("%c", ciphertext[i]);
                }
                printf("\n");
                return 0;
            }
            else
            {
                printf("Error - duplicate characters in the key\n");
                return 1;
            }
        }
        else
        {
            printf("The key should be 26 characters long\n");
            return 1;
        }
    }
    else
    {
        printf("Error\n");
        return 1;
    }
}