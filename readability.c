#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Call all prototype functions in main
// Add count_letters, count_words, count_sentences prototype function

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for string text (Text: ) in main
    string input_text = get_string("Text: ");
    float input_words = count_words(input_text);
    // L = no. of letters / (no. of words/100.0)
    float L = count_letters(input_text) / (input_words / 100.0);
    // S = no. of sentences / (no. of words/100.0)
    float S = count_sentences(input_text) / (input_words / 100.0);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // If index => 16, printf ("Grade 16+") && if index < 1, printf ("Before Grade 1") && else printf int grade number
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (15 >= index >= 1)
    {
        int grade_number = round(index);
        printf("Grade %i\n", grade_number);
    }
}

// Count words
// If text[space_count] != spaceASCII conditional to focus on spaces & reject any other ASCII number, use for/while loop to count number of spaces (ASCII),
// Number of words == number of spaces +1
// Return words space_count
int count_words(string text)
{
    int space = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            space++;
        }
    }
    int word = space + 1;
    return word;
}

// Count sentences
// Use if text[j] conditional to focus on . ! ? ASCII, use while loop to count number of i in text[j] == number of sentences
// Return sentences j
int count_sentences(string text)
{
    int punctuation = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == '.' || text[j] == '!' || text[j] == '?')
        {
            punctuation++;
        }
    }
    return punctuation;
}

// In my younger and more.\0
//  Use for/while loop to count the number of i in text[i], if conditional to reject any spaces ASCII, in proto function
//  letters = characters - words - sentences
//  Return letters i
//  Did not consider other ' ; - characters, maybe use old method of counting isalpha???
int count_letters(string text)
{
    int letter = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (isalpha(text[k]))
        {
            letter++;
        }
    }
    return letter;
}
