#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define ROW 3
#define COL 3
#define X 'X'
#define O 'O'
char boerd[ROW][COL];
int free_space()
{
    int free = 9;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(boerd[i][j]!=' ')
                free--;
        }
    }
    return free;
}
char upperCase(char elm)
{
    return elm>='a' && elm<='z'?elm-('a'-'A'):elm;
}
void fill_boerd()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            boerd[i][j] = ' ';
    }
}
void show_boerd()
{
    for(int i=0;i<COL;i++)
    {   
        if(i==0)
        printf("    %i ",i+1);
        else
        printf("  %i ",i+1);
    }
    printf("\n");
    for(int i=0;i<ROW;i++)
    {
        printf("%i  ",i+1);
        for(int j=0;j<COL;j++)
        {
            if(j!=COL-1)
                printf(" %c |",boerd[i][j]);
            else
                printf(" %c ",boerd[i][j]);
        }
        if(i!=ROW-1)
        printf("\n  -------------\n");
    }
}
int main()
{
    int x,y;
    char player,computer;
    printf("CHOOSE A SAMBLE(X or O):");
    scanf("%c",&player);
    player = upperCase(player);
    computer = (player=='X')?O:X;
    fill_boerd();
    do{
        do{
        printf("CHOOSE A ROW NUMBER  (1-3):");
        scanf("%i",&x);
        printf("CHOOSE A COL NUMBER (1-3):");
        scanf("%i",&y);
        x--;
        y--;
        }while(x>2 || x<0 || y>2 || y<0);
    }while(boerd[x][y]!=' ');
    boerd[x][y] = 'X';
    show_boerd();
    
    printf("%c",computer);
}