#include <cs50.h>
#include <stdio.h>

int quarter(int c);
int dime(int c);
int nickel(int c);

int main(void)
{
    int change, coins;

    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    int qCoins = quarter(change);
    change = change - (25 * qCoins);

    int dCoins = dime(change);
    change = change - (10 * dCoins);

    int nCoins = nickel(change);
    change = change - (5 * nCoins);

    coins = qCoins + dCoins + nCoins + change;

    printf("%i\n", coins);
}

int quarter(int c)
{
    return c / 25;
}

int dime(int c)
{
    return c / 10;
}

int nickel(int c)
{
    return c / 5;
}
