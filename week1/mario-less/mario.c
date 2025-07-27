#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int i, j, k;

    for (i = 0; i < height; i++)
    {
        for (j = (height - 1); j > i; j--)
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
