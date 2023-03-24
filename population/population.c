#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for start size
    int start_size;
    do
    {
        start_size = get_int("Enter starting population size: ");
    }
    while (start_size < 9);

    // Prompt user for end size
    int end_size;
    do
    {
        end_size = get_int("Enter ending population size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    int years = 0;
    int population = start_size;
    while (population < end_size)
    {
        int births = population / 3;
        int deaths = population / 4;
        population += births - deaths;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
