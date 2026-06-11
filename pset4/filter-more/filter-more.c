#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
                            (float) 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempRed;
    int tempGreen;
    int tempBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tempRed = image[i][(width - 1) - j].rgbtRed;
            tempGreen = image[i][(width - 1) - j].rgbtGreen;
            tempBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][(width - 1) - j].rgbtRed = image[i][j].rgbtRed;
            image[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][(width - 1) - j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = tempRed;
            image[i][j].rgbtGreen = tempGreen;
            image[i][j].rgbtBlue = tempBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copying
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    int counter;
    int averageRed;
    int averageGreen;
    int averageBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            averageRed = 0;
            averageGreen = 0;
            averageBlue = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        averageRed += copy[k][l].rgbtRed;
                        averageGreen += copy[k][l].rgbtGreen;
                        averageBlue += copy[k][l].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtRed = round(averageRed / (float) counter);
            image[i][j].rgbtGreen = round(averageGreen / (float) counter);
            image[i][j].rgbtBlue = round(averageBlue / (float) counter);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int GxRed;
    int GxBlue;
    int GxGreen;
    int GyRed;
    int GyBlue;
    int GyGreen;
    int row;
    int column;
    int red;
    int green;
    int blue;

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            GxRed = 0;
            GxBlue = 0;
            GxGreen = 0;
            GyRed = 0;
            GyBlue = 0;
            GyGreen = 0;
            row = 0;
            column = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        row = abs((i - k) - 1);
                        column = abs((j - l) - 1);

                        GxBlue += ((copy[k][l].rgbtBlue) * (Gx[row][column]));
                        GyBlue += ((copy[k][l].rgbtBlue) * (Gy[row][column]));

                        GxRed += ((copy[k][l].rgbtRed) * (Gx[row][column]));
                        GyRed += ((copy[k][l].rgbtRed) * (Gy[row][column]));

                        GxGreen += ((copy[k][l].rgbtGreen) * (Gx[row][column]));
                        GyGreen += ((copy[k][l].rgbtGreen) * (Gy[row][column]));
                    }
                }
            }
            blue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));
            if (blue > 255)
            {
                blue = 255;
            }
            image[i][j].rgbtBlue = blue;

            red = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            if (red > 255)
            {
                red = 255;
            }
            image[i][j].rgbtRed = red;

            green = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            if (green > 255)
            {
                green = 255;
            }
            image[i][j].rgbtGreen = green;
        }
    }
}
