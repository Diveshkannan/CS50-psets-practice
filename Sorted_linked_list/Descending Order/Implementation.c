#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    node *tmp = NULL;

    int temp;

    int N;
    printf("Number of elements:");
    scanf("%i", &N);
    if (N <= 0)
    {
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        node *n = malloc(sizeof(node));

        printf("Number:");
        scanf("%i", &temp);

        n->number = temp;

        if (list == NULL)
        {
            list = n;
            n->next = NULL;
        }
        else
        {
            tmp = NULL;
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {

                if (n->number > ptr->number)
                {
                    n->next = ptr;
                    if (tmp == NULL)
                    {
                        list = n;
                    }
                    else
                    {
                        tmp->next = n;
                    }
                    break;
                }

                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    n->next = NULL;
                    break;
                }

                tmp = ptr;
            }
        }
    }
    int original_list[N];
    int counter = 0;
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        original_list[counter] = ptr->number;
        counter += 1;
    }

    for (int i = 0; i < N; i++)
    {
        printf("Element - %i : %i\n", i + 1, original_list[i]);
    }

    tmp = list;
    while (tmp != NULL)
    {
        node *help = tmp->next;
        free(tmp);
        tmp = help;
    }
}
