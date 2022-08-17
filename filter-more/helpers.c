#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float grey;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grey = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(grey);
            image[i][j].rgbtGreen = round(grey);
            image[i][j].rgbtRed = round(grey);
        }
    }

    return;
}

// Swap the int of each pixel for reflect
void swap(BYTE *a, BYTE *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j].rgbtBlue, &image[i][width - j - 1].rgbtBlue);
            swap(&image[i][j].rgbtGreen, &image[i][width - j - 1].rgbtGreen);
            swap(&image[i][j].rgbtRed, &image[i][width - j - 1].rgbtRed);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Duplicate image
    RGBTRIPLE reference[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            reference[a][b].rgbtBlue = image[a][b].rgbtBlue;
            reference[a][b].rgbtGreen = image[a][b].rgbtGreen;
            reference[a][b].rgbtRed = image[a][b].rgbtRed;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // New value is average of 3x3 box of ORIGINAL pixels
            if (i == 0)
            {
                // Top left & top right pixels
                if (j == 0)
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j + 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j + 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j + 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j + 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j + 1].rgbtRed) / 4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j - 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j - 1].rgbtRed) / 4.0);
                }
                // Upper middle pixels
                else
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j - 1].rgbtBlue + reference[i + 1][j + 1].rgbtBlue + reference[i][j + 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j - 1].rgbtGreen + reference[i + 1][j + 1].rgbtGreen + reference[i][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j - 1].rgbtRed + reference[i + 1][j + 1].rgbtRed + reference[i][j + 1].rgbtRed) / 6.0);
                }
            }
            else if (i == height - 1)
            {
                // Bottom left & bottom right pixels
                if (j == 0)
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j + 1].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i - 1][j + 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j + 1].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i - 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j + 1].rgbtRed + reference[i - 1][j].rgbtRed + reference[i - 1][j + 1].rgbtRed) / 4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i - 1][j - 1].rgbtBlue) / 4.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i - 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i - 1][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i - 1][j - 1].rgbtRed) / 4.0);
                }
                // Bottom middle pixels
                else
                {
                    image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i - 1][j - 1].rgbtBlue + reference[i - 1][j + 1].rgbtBlue + reference[i][j + 1].rgbtBlue) / 6.0);
                    image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i - 1][j - 1].rgbtGreen + reference[i - 1][j + 1].rgbtGreen + reference[i][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i - 1][j].rgbtRed + reference[i - 1][j - 1].rgbtRed + reference[i - 1][j + 1].rgbtRed + reference[i][j + 1].rgbtRed) / 6.0);
                }
            }
            // Side middle pixels
            else if (j == 0 && i > 0 && i < height - 1)
            {
                image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j + 1].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i - 1][j + 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j + 1].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i - 1][j + 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j + 1].rgbtRed + reference[i - 1][j].rgbtRed + reference[i - 1][j + 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j + 1].rgbtRed) / 6.0);
            }
            else if (j == width - 1 && i > 0 && i < height - 1)
            {
                image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i - 1][j - 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j - 1].rgbtBlue) / 6.0);
                image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i - 1][j - 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i - 1][j].rgbtRed + reference[i - 1][j - 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j - 1].rgbtRed) / 6.0);
            }
            // Rest of the center pixels
            else
            {
                image[i][j].rgbtBlue = round((reference[i][j].rgbtBlue + reference[i][j - 1].rgbtBlue + reference[i - 1][j].rgbtBlue + reference[i - 1][j - 1].rgbtBlue + reference[i + 1][j].rgbtBlue + reference[i + 1][j - 1].rgbtBlue + reference[i + 1][j + 1].rgbtBlue + reference[i][j + 1].rgbtBlue + reference[i - 1][j + 1].rgbtBlue) / 9.0);
                image[i][j].rgbtGreen = round((reference[i][j].rgbtGreen + reference[i][j - 1].rgbtGreen + reference[i - 1][j].rgbtGreen + reference[i - 1][j - 1].rgbtGreen + reference[i + 1][j].rgbtGreen + reference[i + 1][j - 1].rgbtGreen + reference[i + 1][j + 1].rgbtGreen + reference[i][j + 1].rgbtGreen + reference[i - 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtRed = round((reference[i][j].rgbtRed + reference[i][j - 1].rgbtRed + reference[i - 1][j].rgbtRed + reference[i - 1][j - 1].rgbtRed + reference[i + 1][j].rgbtRed + reference[i + 1][j - 1].rgbtRed + reference[i + 1][j + 1].rgbtRed + reference[i][j + 1].rgbtRed + reference[i - 1][j + 1].rgbtRed) / 9.0);
            }
        }
    }
    return;
}

// Detect edges
int cap(int rgb)
{
    if (rgb > 255)
    {
        return 255;
    }
    else if (rgb < 0)
    {
        return 0;
    }
    else
    {
        return rgb;
    }
}
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Duplicate image and create black border
    RGBTRIPLE reference[height + 2][width + 2];
    // Top & bottom layer
    for (int b = 0; b < width + 2; b++)
    {
        reference[0][b].rgbtBlue = 0;
        reference[0][b].rgbtRed = 0;
        reference[0][b].rgbtGreen = 0;
        reference[height + 1][b].rgbtBlue = 0;
        reference[height + 1][b].rgbtRed = 0;
        reference[height + 1][b].rgbtGreen = 0;
    }
    // Side layers
    for (int b = 0; b < height + 2; b++)
    {
        reference[b][0].rgbtBlue = 0;
        reference[b][0].rgbtRed = 0;
        reference[b][0].rgbtGreen = 0;
        reference[b][width + 1].rgbtBlue = 0;
        reference[b][width + 1].rgbtRed = 0;
        reference[b][width + 1].rgbtGreen = 0;
    }

    // Copy image
    // Reference should stop at height+1 and width+1, ref starts at [1][1]
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            reference[a + 1][b + 1].rgbtBlue = image[a][b].rgbtBlue;
            reference[a + 1][b + 1].rgbtGreen = image[a][b].rgbtGreen;
            reference[a + 1][b + 1].rgbtRed = image[a][b].rgbtRed;
        }
    }

    typedef struct
    {
        float rgbtBlue;
        float rgbtGreen;
        float rgbtRed;
    } 
    RGBTRIPLE_float;

    RGBTRIPLE_float Gx[height][width];
    RGBTRIPLE_float Gy[height][width];

    for (int j = 1; j < width + 1; j++)
    {
        for (int i = 1; i < height + 1; i++)
        {
            // Gx
            // Case 1: gx.rgbt is >255, Case 2: gx.rgbt is <0
            Gx[i - 1][j - 1].rgbtBlue =
                (float)(-reference[i - 1][j - 1].rgbtBlue + reference[i - 1][j + 1].rgbtBlue - 2 * reference[i][j - 1].rgbtBlue + 2 * reference[i][j + 1].rgbtBlue - reference[i + 1][j - 1].rgbtBlue + reference[i + 1][j + 1].rgbtBlue);

            Gx[i - 1][j - 1].rgbtRed =
                (float)(-reference[i - 1][j - 1].rgbtRed + reference[i - 1][j + 1].rgbtRed - 2 * reference[i][j - 1].rgbtRed + 2 * reference[i][j + 1].rgbtRed - reference[i + 1][j - 1].rgbtRed + reference[i + 1][j + 1].rgbtRed);

            Gx[i - 1][j - 1].rgbtGreen =
                (float)(-reference[i - 1][j - 1].rgbtGreen + reference[i - 1][j + 1].rgbtGreen - 2 * reference[i][j - 1].rgbtGreen + 2 * reference[i][j + 1].rgbtGreen - reference[i + 1][j - 1].rgbtGreen + reference[i + 1][j + 1].rgbtGreen);

            // Gy
            Gy[i - 1][j - 1].rgbtBlue =
                (float)(-reference[i - 1][j - 1].rgbtBlue - 2 * reference[i - 1][j].rgbtBlue - reference[i - 1][j + 1].rgbtBlue + reference[i + 1][j - 1].rgbtBlue + 2 * reference[i + 1][j].rgbtBlue + reference[i + 1][j + 1].rgbtBlue);

            Gy[i - 1][j - 1].rgbtRed =
                (float)(-reference[i - 1][j - 1].rgbtRed - 2 * reference[i - 1][j].rgbtRed - reference[i - 1][j + 1].rgbtRed + reference[i + 1][j - 1].rgbtRed + 2 * reference[i + 1][j].rgbtRed + reference[i + 1][j + 1].rgbtRed);

            Gy[i - 1][j - 1].rgbtGreen =
                (float)(-reference[i - 1][j - 1].rgbtGreen - 2 * reference[i - 1][j].rgbtGreen - reference[i - 1][j + 1].rgbtGreen + reference[i + 1][j - 1].rgbtGreen + 2 * reference[i + 1][j].rgbtGreen + reference[i + 1][j + 1].rgbtGreen);
        }
    }

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {

            image[i][j].rgbtBlue = cap(round((float)sqrt((Gx[i][j].rgbtBlue * Gx[i][j].rgbtBlue) + (Gy[i][j].rgbtBlue * Gy[i][j].rgbtBlue))));
            image[i][j].rgbtGreen = cap(round((float)sqrt((Gx[i][j].rgbtGreen * Gx[i][j].rgbtGreen) + (Gy[i][j].rgbtGreen * Gy[i][j].rgbtGreen))));
            image[i][j].rgbtRed = cap(round((float)sqrt((Gx[i][j].rgbtRed * Gx[i][j].rgbtRed) + (Gy[i][j].rgbtRed * Gy[i][j].rgbtRed))));
        }
    }

    return;
}
