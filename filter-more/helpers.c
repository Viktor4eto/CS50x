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
    RGBTRIPLE same[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            same[i][j] = image[i][j];
        }
    }

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
                        avgBlue += same[y][x].rgbtBlue;
                        avgGreen += same[y][x].rgbtGreen;
                        avgRed += same[y][x].rgbtRed;
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
    //grayscale(height, width, image);
    //blur(height, width, image);
    int soleGY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int soleGX[3][3] = {{-1, 0, 1}, {-2, 0 ,2}, {-1, 0, 1}};

    RGBTRIPLE same[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            same[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //RGBTRIPLE Gy;
            double GYrgbtBlue = 0;
            double GYrgbtGreen = 0;
            double GYrgbtRed = 0;
            //RGBTRIPLE Gx;
            double GXrgbtBlue = 0;
            double GXrgbtGreen = 0;
            double GXrgbtRed = 0;
            //int sole = 0;

                for (int y = i - 1; y < i + 2; y++)
                {
                    if (y == - 1 || y == height + 1)
                        continue;
                    for (int x = j - 1; x < j + 2; x++)
                    {
                        if (x == - 1 || x == width + 1)
                            continue;
                        //Gx:
                        //sole = y%2 + 1;

                        GXrgbtBlue += same[y][x].rgbtBlue*soleGX[y - i + 1][x - j + 1];
                        GXrgbtGreen += same[y][x].rgbtGreen*soleGX[y - i + 1][x - j + 1];
                        GXrgbtRed += same[y][x].rgbtRed*soleGX[y - i + 1][x - j + 1];

                        //Gy:

                        GYrgbtBlue += same[y][x].rgbtBlue*soleGY[y - i + 1][x - j + 1];
                        GYrgbtGreen += same[y][x].rgbtGreen*soleGY[y - i + 1][x - j + 1];
                        GYrgbtRed += same[y][x].rgbtRed*soleGY[y - i + 1][x - j + 1];
                    }
                }

                int B = round(sqrt(pow(GYrgbtBlue, 2.0) + pow(GXrgbtBlue, 2.0)));
                int G = round(sqrt(pow((GYrgbtGreen, 2.0) + pow(GXrgbtGreen, 2.0)));
                int R = round(sqrt(pow(GYrgbtRed, 2.0) + pow(GXrgbtRed, 2.0)));

                if (B > 255)
                    B = 255;
                if (G > 255)
                    G = 255;
                if (R > 255)
                    R = 255;

                image[i][j].rgbtBlue = B;
                image[i][j].rgbtGreen = G;
                image[i][j].rgbtRed = R;
        }
    }
    return;
}
