#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;

    // Prompt the user for a height input between 1 and 8, inclusive.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print the pyramid with the specified height.
    for (int i = 0; i < height; i++)
    {
        // Print the necessary number of spaces before each row of the pyramid.
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print the left half of the pyramid for this row.
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Print the gap between the left and right halves of the pyramid.
        printf("  ");

        // Print the right half of the pyramid for this row.
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Move to the next line to start the next row of the pyramid.
        printf("\n");
    }

    // Exit the program with a status of 0 to indicate success.
    return 0;
}