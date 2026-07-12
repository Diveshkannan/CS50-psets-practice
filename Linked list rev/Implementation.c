#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct turn
{
    int num;
    struct turn *next;
} turn;

int main(void)
{
    // beginning list points nowhere
    turn *list = NULL;

    turn *tmp=NULL;

    int temp;


    int N;
    printf("Number of elements:");
    scanf("%i",&N);
    if (N<=0)
    {
        return 1;
    }

    // need to create 3 elements
    for (int i = 0; i < N; i++)
    {
        // allocating memory
        turn *n = malloc(sizeof(turn));

        // store it in it's num
        printf("Number:");
        scanf("%i",&temp);

        (*n).num=temp;

        list=n;

        if (i==0)
        {
            //1st element is the last element
            (*n).next=NULL;
        }
        else{

            (*n).next=tmp;
        }

         tmp=n;
    }
    int original_list[N];
    tmp=list;
    for(int i=0;i<N;i++)
    {
        original_list[i]=(*tmp).num;
        tmp=(*tmp).next;
    }

    for(int i=0;i<N;i++)
    {
        printf("Element - %i : %i\n",i+1,original_list[i]);
    }
}
