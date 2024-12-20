/* Program 5.7 Tic-Tac-Toe */
#include <stdio.h>
int main(void)
{
    int player = 0;
    int winner = 0;
    int choice = 0;
    int row = 0;
    int column = 0;
    int line = 0;

    char board[3][3] = 
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    /* The main game loop. The game continues for up to 9 turns */
    /* As long as there is no winner */
    for(int i = 0; i<9 && winner ==0; i++)
    {
        /* Display the board*/
        printf("\n\n");
        printf(" %c| %c| %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c| %c| %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c| %c| %c\n", board[2][0], board[2][1], board[2][2]);
        
        player = i%2 + 1; /* Select player*/

        /* get valid player square selection*/
        do
        {
            printf("\nPlayer %d, please enter the number of square"
                                    "where you want to place your %c: ", 
                                    player, (player==1)? 'X':'O');
                scanf("%d", &choice);

                row = --choice/3;           /* Get row index of square */
                column = choice%3;          /* Get column index of square */ 
        }while(choice < 0 || choice > 9 || board[row][column] > '9');
        
        /* insert player symbol */
        board[row][column] = (player == 1) ? 'X': 'O';

        /* Check for a winning line – diagonals first */
        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[0][2] == board[2][0])) 
            winner = player;
        else
        /* Check rows and columns for a winning line */
        for(line = 0; line <= 2; line ++)
            if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
            (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
            winner = player;
    }

    /* Game is over so display the final board */
    printf("\n\n");
    printf(" %c| %c| %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c| %c| %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c| %c| %c\n", board[2][0], board[2][1], board[2][2]);
    
    /* Display result message */
    if(winner == 0)
        printf("\nHow boring, it is a draw\n");
    else
        printf("\nCongratulations, player %d, YOU ARE THE WINNER! \n", winner);    
    return 0;  
}