#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay( int seconds )
{
    int milli_seconds = 1000 * seconds ;
    clock_t start_time = clock() ;
    while ( clock() < start_time + milli_seconds )
        ;
}

void table_displayer( int gunman_stage[] )
{
    int row,column,line_number;

    printf("\n ________________________________________________________");
    printf("\n|  |                        |  |                        |");
    printf("\n|  |        player1         |  |         player2        |");
    printf("\n|__|________________________|__|________________________|\n");

    for( row = 0 ; row < 10 ; row += 2 ){         //There are 5 rows and it's incremented by 2 because 2 gunman printed in one row.
            for( line_number = 1 ; line_number <= 9 ; line_number++ )   //There are 9 lines to print one gunman.
            {
                for( column = row ; column < row +2 ; column++ )       //There are 2 columns so that each line of both players gunman are printed line by line.
                {
                  switch( line_number )
                  {
                   case 1:
                       printf("|  |                        ");
                       break;
                   case 2:
                       if( gunman_stage[column] == 0 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] >= 1 && gunman_stage[column] <= 13 )
                            printf("|  |         ^              ");
                        else{
                            printf("|  |                        ");
                            }
                        break;
                   case 3:
                        if( gunman_stage[column] == 0 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] >= 1 && gunman_stage[column] <= 13 )
                            printf("|  |       ('_')            ");
                        else{
                            printf("|  |                        ");
                            }
                        break;
                   case 4:
                        if( gunman_stage[column] == 0 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] >= 1 && gunman_stage[column] <= 6 )
                            printf("|  |         v              ");
                        else if( gunman_stage[column] >= 7 && gunman_stage[column] <= 13 )
                            printf("|  |         v     ____     ");
                        else{
                            printf("|  |                        ");
                            }
                       break;
                   case 5:
                       if( gunman_stage[column] == 0 || gunman_stage[column] == 1 )
                            printf("|%d |                        ",column);
                        else if( gunman_stage[column] == 2 )
                            printf("|%d |         |              ",column);
                        else if( gunman_stage[column] == 3 )
                            printf("|%d |       / |              ",column);
                        else if( gunman_stage[column] >= 4 && gunman_stage[column] <= 6)
                            printf("|%d |       / | \\            ",column);
                        else if( gunman_stage[column] == 7 )
                            printf("|%d |       / | \\  |   _|    ",column);
                        else if( gunman_stage[column] == 8 )
                            printf("|%d |       / | \\  |   _| @  ",column);
                        else if( gunman_stage[column] == 9 )
                            printf("|%d |       / | \\  |@  _|    ",column);
                        else if( gunman_stage[column] == 10 )
                            printf("|%d |       / | \\  |@  _| @  ",column);
                        else if( gunman_stage[column] == 11 )
                            printf("|%d |       / | \\  |@@ _|    ",column);
                        else if( gunman_stage[column] == 12 )
                            printf("|%d |       / | \\  |@@ _| @  ",column);
                        else if( gunman_stage[column] == 13 )
                            printf("|%d |       / | \\  |@@@_|    ",column);
                        else{
                            printf("|%d |       K I L L E D      ",column);
                            }
                       break;
                   case 6:
                        if( gunman_stage[column] == 0 || gunman_stage[column] == 1 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] == 2 )
                            printf("|  |         |              ");
                        else if( gunman_stage[column] == 3 )
                            printf("|  |      /  |              ");
                        else if( gunman_stage[column] >= 4 && gunman_stage[column] <= 6 )
                            printf("|  |      /  |  \\           ");
                        else if( gunman_stage[column] >= 7 && gunman_stage[column] <= 13 )
                            printf("|  |      /  |  \\ |_|       ");
                        else{
                            printf("|  |                        ");
                            }
                       break;
                   case 7:
                       if( gunman_stage[column] >= 0 && gunman_stage[column] <= 4 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] == 5 )
                            printf("|  |        /               ");
                        else if( gunman_stage[column] >= 6 && gunman_stage[column] <= 13 )
                            printf("|  |        / \\             ");
                        else{
                            printf("|  |                        ");
                            }
                       break;
                   case 8:
                       if( gunman_stage[column] >= 0 && gunman_stage[column] <= 4 )
                            printf("|  |                        ");
                        else if( gunman_stage[column] == 5 )
                            printf("|  |       /                ");
                        else if( gunman_stage[column] >= 6 && gunman_stage[column] <= 13 )
                            printf("|  |       /   \\            ");
                        else{
                            printf("|  |                        ");
                            }
                       break;
                   case 9:
                       printf("|__|________________________");
                       break;
                  }
                }
                printf("|\n");
            }
    }
}

int game_engine(int gunman_stage[] , int player_point , int player_mode , int player_turn )
{
    int random_number_player , shooting_number_player , checker , opponent , player_nature ;

    char shooting_order_player , space ;

    if( player_turn == 1 )
    {
        opponent = 2;
        player_nature = 0;  // 0 means even numbers which are of 1st player gunmans
    }
    else
    {
        opponent = 1;
        player_nature = 1;   // 1 means odd numbers which are of 2nd player gunmans
    }

        if( player_mode == 2 || player_turn == 1 )
        {
            printf("Press Enter to pick a random number for player %d :",player_turn);
            getchar();
        }

        random_number_player = rand() %10 ;
        if(random_number_player%2 == 1 && player_turn == 1 )            //only even number for player1 ,if it's odd it is changed to even by decrementing 1
            random_number_player--;
        if(random_number_player%2 == 0 && player_turn == 2 )            //only odd number for player2 ,if it's even it is changed to odd by incrementing 1
            random_number_player++;

        if( gunman_stage[random_number_player] < 14 )
            gunman_stage[random_number_player]++;                  ////The gunman stage of selected number is increased by one stage
        if( gunman_stage[random_number_player] == 14 )            //13 is the 10th stage which represents gunman with gun and three loaded bullets
            gunman_stage[random_number_player] = 13;            //Only 3 bullets can be loaded totally so 10th stage is maximum

        printf("Random Number of player%d is : %d\n",player_turn,random_number_player);
        if( gunman_stage[random_number_player] >= 9 && gunman_stage[random_number_player] <= 13 && (player_mode == 2 || player_turn == 1) )
        {
            printf("\nDo you want to shoot any of the alive gunman of player%d [y/n] : ",opponent);
            scanf("%c",&shooting_order_player);
            checker = player_point;

            while( shooting_order_player == 'y'&& checker == player_point )            //if killed any gunman , player point increases and loop ends
            {
                printf("\nWhich of the gunman of player%d you want to shoot : ",opponent);
                scanf("%d",&shooting_number_player);

                if( shooting_number_player > 9 ){              //There are only 0 to 9 numbers for both players so if exceed then loop runs again
                    printf("\nThe gunman you have selected is invalid , so select valid gunman.\n");
                    continue;
                }

                if( shooting_number_player %2 == player_nature ){              //even number is player2 ,player2 can not kill himself and vice versa , so loop runs again
                    printf("\nThe gunman you have selected is your gunman , so select gunman of player%d.\n",opponent);
                    continue;
                }
                gunman_stage[shooting_number_player] += 20;      //To indicate that the selected number is killed

                if( gunman_stage[shooting_number_player] >33 ){
                    printf("\nThe gunman you have selected to kill is already dead , so select other gunman.\n");
                    continue;      }

                gunman_stage[random_number_player] -= 2;         //Decremented 2 stages because bullet is got in one stage and loaded in other stage.
                player_point++;         //Killed a gunman so player's point increases
                getchar();
            }
        }
        //Below is the computer's automatic selection of player's gunman to kill
        if( gunman_stage[random_number_player] >= 9 && gunman_stage[random_number_player] <= 13 && player_mode == 1 && player_turn == 2 )
        {
            int highest_stage = 0 ;
            checker = player_point ;

            for( int i = 0 ; i < 9 ; i++ )
                if( gunman_stage[highest_stage] > 13 )
                    highest_stage += 2;

            if( checker == player_point )
            {
                for( int check = 0 ; check < 9 ; check += 2 )
                    if( gunman_stage[check] > gunman_stage[highest_stage] && gunman_stage[check] <= 13 )  //Selecting and killing the gunman with highest stage and also checking for killed gunmans
                        highest_stage = check;

                gunman_stage[highest_stage] += 20;

                gunman_stage[random_number_player] -= 2;
                player_point++;
            }
        }
        if( player_turn == 2 && player_mode == 1 )
            delay(2);
    return gunman_stage , player_point ;

}

int gun_man()
{
    int player1_point = 0 , player2_point = 0 , player_mode ;

    int gunman_stage[10];              //This is the stages of 10 gunmans of both players

    printf("-----------GUN SHOOT GAME-----------\n\n");
    srand(time(0));

    for( int num = 0 ; num < 10 ; num++ )
        gunman_stage[num]=0;

    printf("\n\n1.Single Player\n2.Two Players\n\nEnter the number you want to play : ");
    scanf("%d",&player_mode);

    while(1)
    {
        gunman_stage , player1_point = game_engine( gunman_stage , player1_point , player_mode , 1 );
        gunman_stage , player2_point = game_engine( gunman_stage , player2_point , player_mode , 2 );


        system("cls");

        table_displayer(gunman_stage);

        if( player1_point == 5 )         //if player1 or player2 is 5 points then the player have killed 5 gun mans of other player , so he is the winner.
        {
            printf("\n\n\t\t\t\t\t\t\t\t____________PLAYER1 WON THE GAME_____________");
            return 0;
        }
        if( player2_point == 5 )
        {
            printf("\n\n\t\t\t\t\t\t\t\t____________PLAYER2 WON THE GAME_____________");
            return 0;
        }
    }
}

int main()
{
    char ch = 'y';
    while( ch == 'y' )
    {
        gun_man();
        printf("\n\nDo you want to play again [ y/n ] : ");
        scanf("%c",&ch);
        getchar();
    }
}
