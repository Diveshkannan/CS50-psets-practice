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

        if (list==NULL)
        {
            list=n;
        }
        else if ( n->num < list->num)
        {
            n->next=list;
            list=n;

        }
        else
        {
            for(turn *ptr=list; ptr !=NULL; ptr=ptr->next)
            {

                if (ptr->next == NULL)
                {
                    ptr->next=n;
                    n->next=NULL;
                    break;
                }

                if (n->num < (ptr->next)->num )
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    break;
                }


            }
        }



    }
    int original_list[N];
    turn *tmp=list;
    for(int i=0;i<N;i++)
    {
       for(turn *ptr=tmp; ptr !=NULL; ptr=ptr->next)
       {
           original_list[i]=ptr->num;
           tmp=ptr->next;
           break;
       }
    }

    for(int i=0;i<N;i++)
    {
        printf("Element - %i : %i\n",i+1,original_list[i]);
    }
}
