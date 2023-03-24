#include "helpers.h"
#include <math.h>

// Calculate average RGB value of a pixel
int get_average_rgb(RGBTRIPLE pixel)
{
    return round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
}

// Limit RGB values between 0 and 255
int limit_rgb(int value)
{
    return (value > 255) ? 255 : (value < 0) ? 0 : value;
}

// Swap two RGBTRIPLE values
void swap_pixels(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg_rgb = get_average_rgb(image[i][j]);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg_rgb;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = limit_rgb(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            int sepiaGreen = limit_rgb(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaRed = limit_rgb(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap_pixels(&image[i][j], &image[i][width - j - 1]);
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int kernel_size = 3;
    for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        float sumBlue = 0;
        float sumGreen = 0;
        float sumRed = 0;
        float counter = 0;

        for (int r = -kernel_size / 2; r <= kernel_size / 2; r++)
        {
            if (i + r < 0 || i + r > height - 1)
            {
                continue;
            }

            for (int c = -kernel_size / 2; c <= kernel_size / 2; c++)
            {
                if (j + c < 0 || j + c > width - 1)
                {
                    continue;
                }

                sumBlue += image[i + r][j + c].rgbtBlue;
                sumGreen += image[i + r][j + c].rgbtGreen;
                sumRed += image[i + r][j + c].rgbtRed;
                counter++;
            }
        }

        temp[i][j].rgbtBlue = round(sumBlue / counter);
        temp[i][j].rgbtGreen = round(sumGreen / counter);
        temp[i][j].rgbtRed = round(sumRed / counter);
    }
}

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        image[i][j].rgbtRed = temp[i][j].rgbtRed;
    }

}

return;
}