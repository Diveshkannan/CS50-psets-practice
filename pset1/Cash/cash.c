#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cents=get_int("Change owed:");
     while(cents<=0)
     {
            printf("Please enter more than 0\n");
            cents=get_int("Change owed:");
     }

     int quarter=cents/25;
     cents=cents%25;

     int dimes=cents/10;
     cents=cents%10;

     int nickels=cents/5;
     cents=cents%5;

     int pennies=cents/1;

     int coins=quarter+dimes+nickels+pennies;
     printf("%i\n",coins);
     return 0;
}




