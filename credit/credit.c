// This program checks if a given credit card number is valid using Luhn’s algorithm.
// It then identifies the type of card (AMEX, MASTERCARD, or VISA) based on the number’s length and starting digits.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Enter credit card number: ");

    int sum = 0;
    int position = 0;
    long temp = number;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 1)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    temp = number;
    int length = 0;
    int first = 0;
    int first_two = 0;

    while (temp > 0)
    {
        if (temp < 100 && temp > 9)
        {
            first_two = temp;
        }

        if (temp < 10)
        {
            first = temp;
        }

        temp /= 10;
        length++;
    }

    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
