#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    int length = 0;
    long tempCard = card;

    do
    {
        length++;
        tempCard /= 10;
    }
    while (tempCard > 0);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum1 = 0, sum2 = 0, total = 0;
    long mod1, mod2, d1, d2;
    tempCard = card;

    do
    {
        // for the last & alternate values
        mod1 = tempCard % 10;
        sum1 += mod1;
        tempCard /= 10;

        // for last second and alt values, and add number*2's digits
        mod2 = tempCard % 10;
        mod2 *= 2;      // 6*2 = 12
        d1 = mod2 / 10; // 12/10 = 1.2
        d2 = mod2 % 10;
        sum2 = sum2 + d1 + d2;

        // to remove the second last value
        tempCard /= 10;
    }
    while (tempCard > 0);

    total = sum1 + sum2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        long start = card;

        // to get the starting two digits of the card
        do
        {
            start /= 10;
        }
        while (start >= 100); // 47/10 = 4.7

        if ((length == 13 || length == 16) && (start / 10 == 4))
        {
            printf("VISA\n");
        }
        else if (length == 15 && (start == 34 || start == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (start > 50 && start < 56))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
}
