// This program calculates the approximate U.S. grade level needed to understand a given text, using the Coleman–Liau index.

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Accept the text from the user

    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculation values for Coleman-Liau index

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // Compute the Coleman-Liau index

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int no_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            no_letters++;
        }
    }
    return no_letters;
}

int count_words(string text)
{
    int no_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            no_words++;
        }
    }
    return no_words;
}

int count_sentences(string text)
{
    int no_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            no_sentences++;
        }
    }
    return no_sentences;
}
