#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    char col;
    int num;
} Colors;
int sum(int x, int y)
{
    return x + y;
}
int min(int x, int y)
{
    return x - y;
}
int mult(int x, int y)
{
    return x * y;
}
int powp(int x, int n)
{
    return (n == 0) ? 1 : x * powp(x, n - 1);
}
int length(char str[])
{
    return *str == '\0' ? 0 : 1 + length(str + 1);
}
void print_Color(char str[], char color)
{
    char COLOR[] = "rgybps";
    Colors *colors = (Colors *)malloc(length(COLOR) * sizeof(Colors));
    int len_color = length(COLOR);
    for (int i = 91; i < 97; i++)
    {
        colors[i - 91].col = COLOR[i - 91];
        colors[i - 91].num = i;
    }
    for (int i = 0; i < len_color; i++)
    {
        if (colors[i].col == color)
            printf("\033[%im%s\033[0m", colors[i].num, str);
    }
    free(colors);
}
int Binary(int n, int index)
{
    if (n / 2 == 0)
        return (n % 2) * powp(10, index);
    return n % 2 * powp(10, index) + Binary(n/2, index + 1);
}
int index_Of(char str[], char elm, int len)
{
    if (len > 0)
    {
        return (elm == str[len]) ? len : index_Of(str, elm, len - 1);
    }
    return -1;
}
void menu()
{
    print_Color("\t\tTHE RULES:\n", 'g');
    print_Color("\t1-CHOOSE THE CORRECT ANSWER:", 'g');
}
int main()
{
    int (*ent_fct[])(int, int) = {sum, min, mult, powp, Binary};
    char opertions[] = "+-*^b";
    int num_choice = 4;
    int *Choice = (int *)calloc(num_choice, sizeof(int));
    int len_op = length(opertions);
    srand(time(NULL));
    menu();
        int rand1, rand2, res, index,answer;
        char op;
        do
        {
            rand1 = rand() % 100;
            rand2 = rand() % 100;
            op = opertions[rand() % len_op];
            index = index_Of(opertions, op, length(opertions) - 1);
        } while (op != 'b' && (ent_fct[index])(rand1, rand2) == 0);
        for (int i = 0; i < len_op; i++)
        {
            if (opertions[i] == op && op != 'b')
            {
                res = (ent_fct[i])(rand1, rand2);
                printf("\n\t\t\033[90m%i %c %i\033[0m\n", rand1, op, rand2);
                break;
            }
            if (op == 'b')
            {
                res = (ent_fct[index])(rand1, 0);
                printf("\n\t\t\033[90m(%i)b=2 \033[0m\n", rand1);
                break;
            }
        }
        Choice[rand() % num_choice] = res;
        for (int i = 0; i < num_choice; i++)
        {
            if (Choice[i] != res && op!='b')
                Choice[i] = rand() % 100;
            if(Choice[i] != res && op == 'b')
                Choice[i] = Binary(rand()%100,0);
        }
        for (int i = 0; i < num_choice; i++)
            printf("%i) _ %i\t\t", i + 1, Choice[i]);
        
        printf("\n\n     choose a correct answer:");
        scanf("%i",&answer);
        printf("\n\n");
        for(int i=0;i<num_choice;i++)
        {
            if(Choice[i] == res)
                printf("\033[92m%i) _ %i\033[0m\t\t", i + 1, Choice[i]);
            else
                printf("\033[91m%i) _ %i\033[0m\t\t", i + 1, Choice[i]);
        }
        if(Choice[answer-1] == res)
            print_Color("\n\n \t\tCORRECT\n\n",'g');
        else
            print_Color("\n\n \t\tWRONG\n\n",'r');
        free(Choice);
}