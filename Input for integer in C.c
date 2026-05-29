#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int number;
    char c;
    printf("Number:");
    while((scanf("%i",&number))!=1)
    {

        printf("It's invalid\n");
        c=getchar()
        while((c)!='\n' && c!= EOF)
        {
              c=getchar();
              continue;
        }
        printf("Number:");
    }
    printf("Number:%i\n", *(&number));
}



