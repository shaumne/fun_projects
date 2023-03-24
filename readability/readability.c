#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(void)
{
    // Get input from user
    string text = get_string("Text: ");

    // Initialize variables to count letters, words, and sentences
    int letters = 0, words = 1, sentences = 0;

    // Loop through each character in input
    for (int i = 0; text[i] != '\0'; i++)
    {
        // If character is a letter, increment letter count
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        // If character is a space, increment word count
        else if (text[i] == ' ')
        {
            words++;
        }
        // If character is a sentence-ending punctuation mark, increment sentence count
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Calculate average number of letters per 100 words
    float L = (float) letters / (float) words * 100;

    // Calculate average number of sentences per 100 words
    float S = (float) sentences / (float) words * 100;

    // Calculate Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Output reading level based on index value
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
