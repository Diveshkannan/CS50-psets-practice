//Just actual code's idea

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    long average;
    for (int i = 0; i < height; i++)
    {
        average = 0;
        for (int j = 0; j < width; j++)
        {
            average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    int originalRed;
    int originalGreen;
    int originalBlue;
    for (int i = 0; i < height; i++)
    {
        sepiaRed = 0;
        sepiaGreen = 0;
        sepiaBlue = 0;
        originalRed = 0;
        originalGreen = 0;
        originalBlue = 0;
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    for (int i = 0; i < height; i++)
    {
        temp = 0;
        for (int j = 0; j < width / 2; j++)
        {
            // swapping red colour
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][(width - 1) - j].rgbtRed = temp;

            // swapping Green colour
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            image[i][(width - 1) - j].rgbtGreen = temp;

            // swapping Blue colour
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][(width - 1) - j].rgbtBlue = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed=image[i][j].rgbtRed;
            copy[i][j].rgbtGreen=image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue=image[i][j].rgbtBlue;
        }
    }
    int red;
    int green;
    int blue;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            // top left corner
            if (i == 0 && j == 0)
            {
                for (int k = 0; k <= i + 1; k++)
                {
                    for (int l = 0; l <= j + 1; l++)
                    {
                        red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 4.0);
                image[i][j].rgbtGreen = round(green / 4.0);
                image[i][j].rgbtBlue = round(blue / 4.0);
            }
            // top right corner
            else if (i == 0 && j == width - 1)
            {
                for (int k = 0; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 4.0);
                image[i][j].rgbtGreen = round(green / 4.0);
                image[i][j].rgbtBlue = round(blue / 4.0);
            }
            // bottom left corner
            else if (i == height - 1 && j == 0)
            {
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = 0; l <= j + 1; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 4.0);
                image[i][j].rgbtGreen = round(green / 4.0);
                image[i][j].rgbtBlue = round(blue / 4.0);
            }
            // bottom right corner
            else if (i == height - 1 && j == width - 1)
            {
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 4.0);
                image[i][j].rgbtGreen = round(green / 4.0);
                image[i][j].rgbtBlue = round(blue / 4.0);
            }
            // left side middle
            else if (j == 0)
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = 0; l <= j + 1; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 6.0);
                image[i][j].rgbtGreen = round(green / 6.0);
                image[i][j].rgbtBlue = round(blue / 6.0);
            }
            // top middle
            else if (i == 0)
            {
                for (int k = 0; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 6.0);
                image[i][j].rgbtGreen = round(green / 6.0);
                image[i][j].rgbtBlue = round(blue / 6.0);
            }
            // right side middle
            else if (j == width - 1)
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 6.0);
                image[i][j].rgbtGreen = round(green / 6.0);
                image[i][j].rgbtBlue = round(blue / 6.0);
            }
            // bottom middle
            else if (i == height - 1)
            {

                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 6.0);
                image[i][j].rgbtGreen = round(green / 6.0);
                image[i][j].rgbtBlue = round(blue / 6.0);
            }
            // centre
            else
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                         red += copy[k][l].rgbtRed;
                        green += copy[k][l].rgbtGreen;
                        blue += copy[k][l].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(red / 9.0);
                image[i][j].rgbtGreen = round(green / 9.0);
                image[i][j].rgbtBlue = round(blue / 9.0);
            }
        }
    }
}
