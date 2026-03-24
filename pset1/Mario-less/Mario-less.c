#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n=get_int("Number of rows:");
    for (int row=0;row<n;row++)
    {
        for(int space=0;space<n-row;space++)
        {
            printf(" ");
        }
        for(int col=0;col<=row;col++)
        {
            printf("#");
        }
        printf("\n");
    }
}