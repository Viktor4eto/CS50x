#include "helpers.h"
#include <math.h>
#include <stdio.h>

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
            int count = 0;
            int avgBlue = 0;
            int avgGreen = 0;
            int avgRed = 0;

            //if (i != 0 && j != 0 && i != height - 1 && j != width - 1)
            //{
                for (int y = i - 1; y < i + 2; y++)
                {
                    if (y == -1 || y == height + 1)
                    {
                        continue;
                    }
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        if (x == -1 || x == width + 1)
                        {
                            continue;
                        }
                        count++;
                        avgBlue += image[y][x].rgbtBlue;
                        avgGreen += image[y][x].rgbtGreen;
                        avgRed += image[y][x].rgbtRed;
                    }
                }
                image[i][j].rgbtBlue = round(avgBlue/count);
                image[i][j].rgbtGreen = round(avgGreen/count);
                image[i][j].rgbtRed = round(avgRed/count);
            //}
            //else if (i == 0 && j != 0 && j )
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE Gy;
            Gy.rgbtBlue = 0;
            Gy.rgbtGreen = 0;
            Gy.rgbtRed = 0;
            RGBTRIPLE Gx;
            Gx.rgbtBlue = 0;
            Gx.rgbtGreen = 0;
            Gx.rgbtRed = 0;
            int sole = 0;
                for (int y = i - 1; y < i + 2; y++)
                {
                    if (y == -1 || y == height + 1)
                    {
                        continue;
                    }
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        if (x == -1 || x == width + 1)
                        {
                            continue;
                        }
                        //Gx:
                        //sole = y%2 + 1;


                        if (x == j && y != i)
                        {
                            if (y > i)
                                sole = 2;
                            else
                                sole = -2;
                        }
                        else if (x != j && y != i)
                        {
                            if (y > i)
                                sole = 1;
                            else
                                sole = -1;
                        }

                        Gx.rgbtBlue += image[y][x].rgbtBlue*sole;
                        Gx.rgbtGreen += image[y][x].rgbtGreen*sole;
                        Gx.rgbtRed += image[y][x].rgbtRed*sole;

                        //Gy:

                        if (y == i && x != j)
                        {
                            if (y > i)
                                sole = 2;
                            else
                                sole = -2;
                        }
                        else if (y != i && x != j)
                        {
                            if (y > i)
                                sole = 1;
                            else
                                sole = -1;
                        }


                        Gy.rgbtBlue += image[y][x].rgbtBlue*sole;
                        Gy.rgbtGreen += image[y][x].rgbtGreen*sole;
                        Gy.rgbtRed += image[y][x].rgbtRed*sole;
                    }
                }

                image[i][j].rgbtBlue = round(sqrt(pow((double) Gy.rgbtBlue, 2.0) + pow((double) Gx.rgbtBlue, 2.0)));
                image[i][j].rgbtGreen = round(sqrt(pow((double) Gy.rgbtGreen, 2.0) + pow((double) Gx.rgbtGreen, 2.0)));
                image[i][j].rgbtRed = round(sqrt(pow((double) Gy.rgbtRed, 2.0) + pow((double) Gx.rgbtRed, 2.0)));
        }
    }
    return;
}
