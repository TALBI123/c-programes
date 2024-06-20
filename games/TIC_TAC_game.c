#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define ROW 3
#define COL 3
#define X 'X'
#define O 'O'
char boerd[ROW][COL];
//this is a TIC TAC  TOE GAME IN C 
int free_space()
{
    int free = 9;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (boerd[i][j] != ' ')
                free--;
        }
    }
    return free;
}
char upperCase(char elm)
{
    return elm>='a' && elm<='z'?elm-('a'-'A'):elm;
}
char winner(char win)
{
    int count1, count2;
    for (int i = 0; i < ROW; i++)
    {
        count1 = 0, count2 = 0;
        for (int j = 0; j < COL; j++)
        {
            if (boerd[i][j] == win)
                count1++;
            if (boerd[j][i] == win)
                count2++;
        }
        if (count1 == COL)
            return 'w';
        if (count2 == ROW)
            return 'w';
    }
    count1 = 0, count2 = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (boerd[i][j] == win && i == j)
                count1++;
            if(boerd[i][j] == win && i == ROW-1-j)
                count2++;
        }
    }
    if (count1 == COL)
        return 'w';
    if (count2 == ROW)
        return 'w';
    return ' ';
}
void fill_boerd()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            boerd[i][j] = ' ';
    }
}
void show_boerd()
{
    for (int i = 0; i < COL; i++)
    {
        if (i == 0)
            printf("    %i ", i + 1);
        else
            printf("  %i ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%i  ", i + 1);
        for (int j = 0; j < COL; j++)
        {
            if (j != COL - 1)
                printf(" %c |", boerd[i][j]);
            else
                printf(" %c ", boerd[i][j]);
        }
        if (i != ROW - 1)
            printf("\n  -------------\n");
    }
}
int main()
{
    int x, y;
    char player, computer;
    srand(time(NULL));
    do
    {
        printf("\nCHOOSE A SAMBLE(X or O):");
        scanf(" %c", &player);
        player = upperCase(player);
    } while (player != X && player != O);
    computer = (player == 'X') ? O : X;
    fill_boerd();
    do
    {
        printf("\n");
        system("pause");
        system("cls");
        do
        {
            printf("\nCHOOSE A ROW NUMBER  (1-3):");
            scanf("%i", &x);
            printf("CHOOSE A COL NUMBER (1-3):");
            scanf("%i", &y);
            x--;
            y--;
            if (x > 2 || x < 0 || y > 2 || y < 0)
                continue;
        } while (boerd[x][y] != ' ');
        boerd[x][y] = player;
        do
        {
            x = rand() % ROW;
            y = rand() % COL;
        } while (boerd[x][y] != ' ' && free_space() != 0);
        boerd[x][y] = computer;
        show_boerd();
        if (winner(computer) == 'w')
        {
            printf("\n\n\tYOU LOSE\n");
            break;
        }
        if (winner(player) == 'w')
        {
            printf("\n\n\tYOU WIN\n");
            break;
        }
        if(free_space()==0 && 
        ( winner(player)=='w' || winner(computer)=='w'))
            printf("\n\tNO ONE WIN\n");
    } while (free_space() != 0);
}