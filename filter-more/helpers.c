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
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;

            image[i][j].rgbtBlue = round(sum/3.0);
            image[i][j].rgbtGreen = round(sum/3.0);
            image[i][j].rgbtRed = round(sum/3.0);
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

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = save.rgbtBlue;
            image[i][width - j - 1].rgbtGreen = save.rgbtGreen;
            image[i][width - j - 1].rgbtRed = save.rgbtRed;
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
            double count = 0;
            int avgBlue = 0;
            int avgGreen = 0;
            int avgRed = 0;

            //if (i != 0 && j != 0 && i != height - 1 && j != width - 1)
            //{
                for (int y = i - 1; y < i + 2; y++)
                {
                    if (y == -1 || y == height)
                    {
                        continue;
                    }
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        if (x == -1 || x == width)
                            continue;

                        count++;
                        avgBlue += image[y][x].rgbtBlue;
                        avgGreen += image[y][x].rgbtGreen;
                        avgRed += image[y][x].rgbtRed;
                    }
                }
                image[i][j].rgbtBlue = (int) round(avgBlue/count);
                image[i][j].rgbtGreen = (int) round(avgGreen/count);
                image[i][j].rgbtRed = (int) round(avgRed/count);
            //}
            //else if (i == 0 && j != 0 && j )
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    grayscale(height, width, image);
    int soleGY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int soleGX[3][3] = {{-1, 0, 1}, {-2, 0 ,2}, {-1, 0, 1}};

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
                    if (y == - 1 || y == height + 1)
                    {
                        continue;
                    }
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        if (x == - 1 || x == width + 1)
                        {
                            continue;
                        }
                        //Gx:
                        //sole = y%2 + 1;


                        Gx.rgbtBlue += image[y][x].rgbtBlue*soleGX[y - i + 1][x - j + 1];
                        Gx.rgbtGreen += image[y][x].rgbtGreen*soleGX[y - i + 1][x - j+ 1];
                        Gx.rgbtRed += image[y][x].rgbtRed*soleGX[y - i + 1][x - j + 1];

                        //Gy:


                        Gy.rgbtBlue += image[y][x].rgbtBlue*soleGY[y - i + 1][x - j + 1];
                        Gy.rgbtGreen += image[y][x].rgbtGreen*soleGY[y - i + 1][x - j + 1];
                        Gy.rgbtRed += image[y][x].rgbtRed*soleGY[y - i + 1][x - j + 1];
                    }
                }

                image[i][j].rgbtBlue = round(sqrt(pow((double) Gy.rgbtBlue, 2.0) + pow((double) Gx.rgbtBlue, 2.0)));
                image[i][j].rgbtGreen = round(sqrt(pow((double) Gy.rgbtGreen, 2.0) + pow((double) Gx.rgbtGreen, 2.0)));
                image[i][j].rgbtRed = round(sqrt(pow((double) Gy.rgbtRed, 2.0) + pow((double) Gx.rgbtRed, 2.0)));
        }
    }
    return;
}
