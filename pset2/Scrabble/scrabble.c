#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
    1, 4, 4, 8, 4, 10
    };

int compute_score(string player);

int main(void)
{
       string player1=get_string("Player 1:");
       string player2=get_string("Player 2:");

       int score1=compute_score(player1);
       int score2=compute_score(player2);

       if (score1>score2)
       {
              printf("Player1 wins!!\n");
       }
       else if (score1<score2)
       {
              printf("Player2 wins!!\n");
       }
       else
       {
              printf("Tie!!\n");
       }
       return 0;
}

int compute_score(string player)
{
       int index;
       int score=0;
       for(int play=0,n=strlen(player);play<n;play++)
       {
              if (isalpha(player[play]))
              {
                     index=toupper(player[play])-'A';
                     score+=POINTS[index];
              }
       }
       return score;
}



