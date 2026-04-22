#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void result(int rank);

float coleman_index(int words, int sentences, int letters);

int main(void)
{
    string text = get_string("Text:");

    if (text[0] == '\0')
    {
        printf("Text is empty\n");
        return 1;
    }
    int word_count = 0;
    int sentence_count = 0;
    int letter_count = 0;

     for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]))
        {

            letter_count++;
        }

        else if (text[i] == ' ')
        {
            if (i<n-1 && isalpha(text[i+1]))
            {
                word_count++;
            }
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            if (i > 0 && isalpha(text[i - 1]))
            {
                sentence_count++;
            }
        }
    }
    if (isalpha(text[0]))
    {
        word_count+=1;
    }
    float index = coleman_index(word_count, sentence_count, letter_count);
    int grade = round(index);
    result(grade);
    return 0;
}

void result(int rank)
{
    if (rank < 1)
    {
        printf("Before grade 1\n");
    }
    else if (rank >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rank);
    }
}

float coleman_index(int words, int sentences, int letters)
{
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    float cole = 0.0588 * L - 0.296 * S - 15.8;
    return cole;
}
