// This program simulates a two-player Scrabble-like game where players enter words, and the program calculates their scores based on letter values.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute(string word);

int main(void)
{
    // Prompt the user for input
    string user_1 = get_string("Player 1: ");
    string user_2 = get_string("Player 2: ");
    // Calculate the score for both the users
    int score1 = compute(user_1);
    int score2 = compute(user_2);
    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tied!\n");
    }
}

int compute(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
        else
        {
            score += 0;
        }
    }
    return score;
}
