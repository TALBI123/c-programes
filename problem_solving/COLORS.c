#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct {
    char col;
    int num;
}Colors;
char COLOR[] = "rgybps";
char *_color[] = {"red","green","yellow","blue","purpel","skey bleu"};
int length(char str[])
{
    return *str == '\0' ? 0 : 1 + length(str+1);
}
void upperCase(char str[])
{
    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z')
            str[i] += - ('a' -'A');
        i++;
    }
}
void Color(char str[],char color)
{
    Colors *colors =(Colors *) malloc(length(COLOR) * sizeof(Colors));
    int len_color = length(COLOR);
    for(int i=91;i<97;i++)
    {
        colors[i-91].col = COLOR[i-91] ;
        colors[i-91].num = i;
    }
    for(int i = 0;i<len_color;i++)
    {
        if(colors[i].col == color)
            printf("\033[%im%s\033[0m",colors[i].num,str);
    }
}
void menu()
{
    printf("\t\t\033[90m---menu---\033[0m\n");
    int num = 91;
    for(int i=0;i<length(COLOR);i++)
        printf("\t\033[%im to get \"%s\" choose '%c\033[0m \n",num++,_color[i],COLOR[i]);
}
int main()
{
    char MY_name[] = "mohamed talbi";
    menu();
    upperCase(MY_name);
    Color(MY_name,'r');
}