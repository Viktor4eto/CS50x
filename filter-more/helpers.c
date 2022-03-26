#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgb = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);

            image[i][j].rgbtBlue = rgb;
            image[i][j].rgbtGreen = rgb;
            image[i][j].rgbtRed = rgb;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE save;
            save.rgbtBlue = image[i][j].rgbtBlue;
            save.rgbtGreen = image[i][j].rgbtGreen;
            save.rgbtRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j].rgbtRed;

            image[i][width - j].rgbtBlue = save.rgbtBlue;
            image[i][width - j].rgbtGreen = save.rgbtGreen;
            image[i][width - j].rgbtRed = save.rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int avgBlue =
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
