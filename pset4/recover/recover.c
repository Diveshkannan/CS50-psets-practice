#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        return 1;
    }
    BYTE buffer[512];
    bool jpeg_finder;
    int file_num = 0;
    bool file_open = false;
    string file_name = malloc(8);
    int size;
    int pattern[] = {255, 216, 255};
    if (file_name == NULL)
    {
        return 1;
    }
    while (((size = fread(buffer, 1, 512, file)) == 512))
    {
        jpeg_finder = false;
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                if (buffer[i] <= (200 + (255 - 216)) && buffer[i] >= (200 + (239 - 216) + 1))
                {
                    jpeg_finder = true;
                }
            }
            else if (i!=3 && buffer[i] == pattern[i])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (jpeg_finder)
        {
            if (file_num < 10)
            {
                sprintf(file_name, "00%i.jpg", file_num);
            }
            else if (file_num < 100)
            {
                sprintf(file_name, "0%i.jpg", file_num);
            }
            else
            {
                sprintf(file_name, "%i.jpg", file_num);
            }
            FILE *jpeg = fopen(file_name, "wb");
            file_num++;
            file_open = true;
            fwrite(buffer, 1, 512, jpeg);
            fclose(jpeg);
        }
        else
        {
            if (file_open)
            {
                FILE *jpeg_continuous = fopen(file_name, "a");
                fwrite(buffer, 1, 512, jpeg_continuous);
                fclose(jpeg_continuous);
            }
        }
    }

    if (size == 512)
    {
        free(file_name);
        fclose(file);
        return 0;
    }
    else if (size > 0 && size < 512)
    {
        jpeg_finder = false;
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                if (buffer[i] <= (200 + (255 - 216)) && buffer[i] >= (200 + (239 - 216) + 1))
                {
                    jpeg_finder = true;
                }
            }
            else if (i!=3 && buffer[i] == pattern[i])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        if (jpeg_finder)
        {
            file_num++;
            if (file_num < 10)
            {
                sprintf(file_name, "00%i.jpg", file_num);
            }
            else if (file_num < 100)
            {
                sprintf(file_name, "0%i.jpg", file_num);
            }
            else
            {
                sprintf(file_name, "%i.jpg", file_num);
            }
            file_name[7] = '\0';
            FILE *jpeg = fopen(file_name, "wb");
            file_open = true;
            fwrite(buffer, 1, size, jpeg);
            fclose(jpeg);
        }
        else
        {
            if (file_open)
            {
                FILE *jpeg_continuous_final = fopen(file_name, "a");
                fwrite(buffer, 1, size, jpeg_continuous_final);
                fclose(jpeg_continuous_final);
            }
        }
    }

    free(file_name);
    fclose(file);
}
