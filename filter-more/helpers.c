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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgBlue = 0;
            int avgGreen = 0;
            int avgRed = 0;
            if (i != 0 && j != 0 && i != height - 1 && j != width - 1)
            {
                for (int y = i - 1; y < i + 2; y++)
                {
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        avgBlue += image[y][x].rgbtBlue;
                        avgGreen += image[y][x].rgbtGreen;
                        avgRed += image[y][x].rgbtRed;
                    }
                }
                image[i][j].rgbtBlue = round(avgBlue/9);
                image[i][j].rgbtGreen = round(avgGreen/9);
                image[i][j].rgbtRed = round(avgRed/9);
            }
            //else if (i == 0 && j != 0 && j )
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
