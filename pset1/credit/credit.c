#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

bool luhn(long duplicate);
void card_type(string number);

int main(void)
{
       long card=get_long("Card number:");
       char num[32];
       sprintf(num,"%ld",card);
       if (luhn(card))
       {
              card_type(num);
       }
       else
       {
              printf("INVALID\n");
       }
}

bool luhn(long duplicate)
{
       int counter=0;
       int product=0;
       int temp=0;
       while (duplicate)
       {
              if (counter%2!=0)
              {
                  temp=(duplicate%10)*2;
                  while (temp)
                  {
                     product+=temp%10;
                     temp/=10;
                  }
              }
              else
              {
                  product+=duplicate%10;
              }
              duplicate/=10;
              counter++;
       }
       return (product%10==0);
}

void card_type(string number)
{
       int len=strlen(number);
       if ( (len==15) && ( (number[0]=='3' && number[1]=='4')|| (number[0]=='3' && number[1]=='7')))
       {
              printf("AMEX\n");
       }
       else if ((len==13 || len==16) && number[0]=='4')
       {
              printf("VISA\n");
       }
       else if ((len)==16 && ( (number[0]=='5' && number[1]=='1') || ( number[0]=='5' && number[1]=='2') || (number[0]=='5' && number[1]=='3') || (number[0]=='5' && number[1]=='4') || (number[0]=='5' && number[1]=='5')))
       {
              printf("MASTERCARD\n");
       }
       else
       {
              printf("INVALID\n");
       }
}
