#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n=get_int("Number of rows:");
    for (int row=0;row<n;row++)
    {
        for(int lspace=0;lspace<n-row;lspace++)
        {
            printf(" ");
        }
        for(int lcol=0;lcol<=row;lcol++)
        {
            printf("#");
        }
        printf(" ");
        for(int rcol=0;rcol<=row;rcol++)
        {
            printf("#");
        }
        printf("\n");
    }
}
