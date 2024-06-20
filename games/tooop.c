#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char bored[3][3] ;
void tmatrixial(){
    for(int i = 0;i<COL ; i++){
        for(int j = 0;j<ROW ;j++){
            bored[i][j]=' ' ;
        }
    }
}
void matrix(){
    int i , j ;
    for(i=0;i<COL ; i++){
        for(j=0 ; j<ROW ; j++){
            if(j!=ROW-1)
                printf("%c |",bored[i][j]) ;
        }
        if(i!=COL-1)
            printf("\n----------\n") ;
    }
}
int main()
{
    tmatrixial() ;
    matrix() ;
    return 0;
}