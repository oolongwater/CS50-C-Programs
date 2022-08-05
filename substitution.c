#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_keyletters(string text);

// The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        int letter_count_key = count_keyletters(key);
        // Check if 26 letters in key
        if (letter_count_key == 26)
        { // Reject if letters are repeated
            // Count the letters over two times (j and k = j+1), if repeated key[j or k], count>1
            for (int j = 0; j < strlen(key); j++)
            {
                for (int k = j + 1; k < strlen(key); k++)
                {
                    if (key[j] == key[k])
                    {
                        printf("Please input a key with non-repeating letters");
                        return 1;
                    }
                }
            }
            for (int h = 0; key[h]; h++)
            {
                key[h] = toupper(key[h]);
            }
            string plaintext = get_string("plaintext: \n");
            char cipherchar;
            for (int p_counter = 0; p_counter < strlen(plaintext); p_counter++)
            {
                char current_char = plaintext[p_counter];
                if ('a' <= current_char && current_char <= 'z')
                {
                    cipherchar = key[plaintext[p_counter] - 'a'];
                    cipherchar = tolower(cipherchar);
                }
                else if ('A' <= current_char && current_char <= 'Z')
                {
                    cipherchar = key[current_char - 'A'];
                }
                else
                {
                    cipherchar = current_char;
                }
                plaintext[p_counter] = cipherchar;
            }
            printf("ciphertext: %s\n", plaintext);
            return 0;
            // Create array of 26 alphabets? (lowercase/uppercase? --> use isupper/islower)
        }
        else
        {
            printf("Please input a key with 26 letters");
            return 1;
        }
    }
    else
    {
        printf("Please input a key");
        return 1;
    }
}
// Function to verify 26 letters and confirm all are letters
int count_keyletters(string text)
{
    int letter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
        else if (isalpha(text[i] != true))
        {
            printf("Please input an alphabet key");
            return 1;
        }
    }
    return letter;
}