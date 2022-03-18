#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // Prompt user for int
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    // For each row
    for (int i = 0; i < n; i++)
        // For each column
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
            int x = 10;
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Make a new row
        printf("\n");
    }
}
