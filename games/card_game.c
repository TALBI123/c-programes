#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define ROW 4
#define COL 5
typedef struct
{
    int col;
    int row;
} Matrix;
typedef struct
{
    char color;
    int number;
} COLOR;
typedef struct
{
    char char1;
    char char2;
} Double_char;
Double_char boerd[ROW][COL];
char letters[] = "azertyuiop";
int length(char str[])
{
    return *str == '\0' ? 0 : 1 + length(str + 1);
}
int free_space()
{
    int free = ROW * COL;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (boerd[i][j].char2 != '?')
                free--;
        }
    }
    return free;
}
void print_color(char elm, char _COLOR)
{
    COLOR colors[] = {{'r', 91}, {'g', 92}, {'w', 0}};
    int i = 0, numb_color = 3;
    for (i = 0; i < numb_color; i++)
    {
        if (colors[i].color == _COLOR)
            break;
    }
    printf("\033[%im%c\033[0m", colors[i].number, elm);
}
bool check(Matrix arr1[])
{
    char c[2];
    for (int i = 0; i < 2; i++)
        c[i] = boerd[arr1[i].row][arr1[i].col].char1;
    if (c[0] == c[1])
        return true;
    return false;
}
int free_space2(int arr[], int size)
{
    int free = size - 1;
    for (int i = 0; i < size; i++)
        if (arr[i] == 0)
            free--;
}
void show_boerd2(Matrix arr[], char COLOR1)
{
    int count = 0;
    bool prv = false;
    printf("     ");
    for (int i = 0; i < COL; i++)
    {
        printf(" %i  ", i + 1);
    }
    printf("\n    ---------------------\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%i - ", i + 1);
        for (int j = 0; j < COL; j++)
        {
            if (j != COL - 1)
            {
                if (arr[count].row == i && arr[count].col == j)
                {
                    printf("| ");
                    print_color(boerd[i][j].char2, COLOR1);
                    printf(" ");
                    count++;
                }
                else
                {
                    if (prv)
                        printf(" %c |", boerd[i][j].char2);
                    else
                        printf("| %c ", boerd[i][j].char2);
                }
            }
            else
            {
                if (arr[count].row == i && arr[count].col == j)
                {
                    printf("| ");
                    print_color(boerd[i][j].char2, COLOR1);
                    printf(" |");
                    count++;
                    prv = true;
                }
                else
                {
                    if (prv)
                        printf(" %c |", boerd[i][j].char2);
                    else
                        printf("| %c |", boerd[i][j].char2);
                }
            }
        }
        printf("\n    ---------------------\n");
    }
}
void fill_boerd(char elm)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (elm == '1')
                boerd[i][j].char1 = '?';
            else
                boerd[i][j].char2 = '?';
        }
    }
}
void menu()
{
}
void fill_w_lett()
{
    int len_lett = length(letters);
    int arr[len_lett];
    int _rand;
    bool check;
    srand(time(NULL));
    for (int i = 0; i < len_lett; i++)
        arr[i] = 2;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            check = false;
            do
            {
                _rand = rand() % len_lett;
                if (free_space2(arr, len_lett - 1) == 0)
                {
                    check = true;
                    break;
                }
            } while (arr[_rand] == 0);
            boerd[i][j].char1 = letters[_rand];
            arr[_rand] -= 1;
        }
    }
}
void num_elm()
{
    int row, col, next_row, next_col;
    int next_row2, next_col2, count, count2 = 0;
    bool check;
    for (int i = 0; i < ROW * COL; i++)
    {
        row = i / COL;
        col = i % COL;
        check = false;
        count = 0;
        for (int j = 0; j < ROW * COL; j++)
        {
            next_row = j / COL;
            next_col = j % COL;
            for (int k = 0; k < i; k++)
            {
                next_row2 = k / COL;
                next_col2 = k % COL;
                if (boerd[next_row2][next_col2].char1 == boerd[row][col].char1)
                {
                    check = true;
                    break;
                }
            }
            if (check)
                break;
            if (boerd[row][col].char1 == boerd[next_row][next_col].char1)
                count++;
        }
        if (count > 1)
            printf("%i - %c repeat %i times\n", count2++, boerd[row][col], count);
    }
}
void show_boerd();
int main()
{
    Matrix *arr = (Matrix *)malloc(2 * sizeof(Matrix));
    for (int i = 0; i < 2; i++)
    {
        arr[i].row = 68;
        arr[i].col = 88;
    }
    system("cls");
    fill_boerd('1');
    fill_boerd('2');
    fill_w_lett();
    show_boerd();
    show_boerd2(arr, 'w');
    printf("\n\n");
    int num1, num2, incr = 0;
    do
    {
        do
        {
            do
            {
                printf("Enter a row number (1 - 4):");
                scanf("%i", &num1);
                printf("Enter a col number (1 - 5):");
                scanf("%i", &num2);
            } while ((num1 < 1 || num1 > ROW) || num2 > COL || num2 < 1);
            num1--, num2--;
        } while (boerd[num1][num2].char2 != '?');
        boerd[num1][num2].char2 = boerd[num1][num2].char1;
        arr[incr].row = num1;
        arr[incr++].col = num2;
        if (!check(arr))
            show_boerd2(arr, 'w');
        if (incr == 2)
        {
            if (check(arr))
            {
                printf("\n\t\033[92mare the same\033\n\n[0m");
                show_boerd2(arr, 'g');
            }
            else
            {
                printf("\n\t\033[91mare not the same\033\n\n[0m");
                show_boerd2(arr, 'r');
                for (int i = 0; i < 2; i++)
                    boerd[arr[i].row][arr[i].col].char2 = '?';
                system("pause");
                show_boerd2(arr,'w');
            }
            incr = 0;
        }
    } while (free_space() != 0);
}
void show_boerd()
{
    printf("     ");
    for (int i = 0; i < COL; i++)
    {
        printf(" %i  ", i + 1);
    }
    printf("\n    ---------------------\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%i - ", i + 1);
        for (int j = 0; j < COL; j++)
        {
            if (j != COL - 1)
                printf("| %c ", boerd[i][j].char1);
            else
                printf("| %c |", boerd[i][j].char1);
        }
        printf("\n    ---------------------\n");
    }
}