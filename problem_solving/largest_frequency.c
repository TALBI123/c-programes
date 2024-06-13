#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Find the number with the highest
// frequency in an integer array.
typedef struct
{
    int num;
    int frq;
} Lrgfq;
int maximum(Lrgfq *arr, int size)
{
    if (size > 0)
    {
        int max = maximum(arr, size - 1);
        return max > arr[size].frq ? max : arr[size].frq;
    }
    return arr[size].frq;
}
int main()
{
    int arr[] = {6, 8, 7, 6, 3, 4, 6, 8, 9, 0, 5, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    int count1, count2 = 0;
    bool check;
    for (int i = 0; i < size; i++) // O(n^3)
    {
        count1 = 0;
        check = false;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < i; k++)
                if (arr[i] == arr[k])
                    check = true;
            if (check)
                break;
            if (arr[i] == arr[j])
                count1++;
        }
        if (!check && count1 > 1)
            count2++;
    }
    Lrgfq *arr_L = (Lrgfq *)malloc(count2 * sizeof(Lrgfq));
    count2 = 0;
    for (int i = 0; i < size; i++) // O(n^3)
    {
        count1 = 0;
        check = false;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < i; k++)
                if (arr[i] == arr[k])
                    check = true;
            if (check)
                break;
            if (arr[i] == arr[j])
                count1++;
        }
        if (!check && count1 > 1)
        {
            arr_L[count2].num = arr[i];
            arr_L[count2++].frq = count1;
        }
    }
    int max = maximum(arr_L, count2);
    for (int i = 0; i < count2; i++)
    {
        if (arr_L[i].frq == max)
            printf(" %i is the number with highest frequency", arr_L[i].num);
    }
}