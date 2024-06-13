#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// o(n^3)
typedef struct
{
    int num;
    int frq;
} largest_frequency;
int maximum(largest_frequency *array, int size)
{
    if (size > 0)
    {
        int max = maximum(array, size - 1);
        return max > array[size].frq ? max : array[size].frq;
    }
    return array[size].frq;
}
int main()
{
    int tab[] = {5, 7, 8, 8, 9, 8, 9, 0, 5, 3};
    int size = sizeof(tab) / sizeof(int);
    int count, count2 = 0;
    bool check;
    for (int i = 0; i < size; i++)
    {
        check = false;
        count = 0;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (tab[i] == tab[k])
                    check = true;
            }
            if (check)
                break;
            if (tab[i] == tab[j])
                count++;
        }
        if (!check && count > 1)
            count2++;
    }
    largest_frequency *l_fr = (largest_frequency *)malloc(count2 * sizeof(largest_frequency));
    count2 = 0;
    for (int i = 0; i < size; i++)
    {
        check = false;
        count = 0;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (tab[i] == tab[k])
                    check = true;
            }
            if (check)
                break;
            if (tab[i] == tab[j])
                count++;
        }
        if (!check && count > 1)
        {
            l_fr[count2].num = tab[i];
            l_fr[count2++].frq = count;
        }
    }
    int max = l_fr[0].frq;
    printf("\nThe lagest frequency is :%i",maximum(l_fr,count2-1));
    free(l_fr);
}