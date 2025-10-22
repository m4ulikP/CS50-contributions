// The program prompts the user for a height between 1 and 8 and prints two side-by-side pyramids of that height.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height (1-8): ");
    }
    while (height < 1 || height > 8);
    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
