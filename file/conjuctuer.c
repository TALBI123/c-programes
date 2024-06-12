#include <stdio.h>
#include <stdlib.h>
// The goal of this exercise is to implement the Collatz function 
// in C and write several associated functions to compute successive 
// iterations until reaching 1, the flight time (number of iterations 
// until 1), and the maximum altitude (highest value reached). This also 
// includes displaying the successive values in direct and reverse order.
int collatz(int n)
{
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}
int compter(int n)
{
    if (n == 1)
        return 1;
    return 1 + compter(collatz(n));
}
//v1
int max_collatz(int n)
{
    if (n == 1)
        return 1;
    int max = max_collatz(collatz(n));
    if(max<n)
        return n;
    else
        return max;
}
//v2
int max_collatz(int n)
{
    if (n == 1)
        return 1;
    int max = max_collatz(collatz(n));
    return max<n ? n : max;
}
//print result
void sycr1(int n)
{
    if (n == 1)
    {
        printf("\t1\t");
        return;
    }
    printf("%i\t", n);
    sycr1(collatz(n));
}
//*s
//stock result in an array
void syracuse(int n, int *squence, int *index)
{
    squence[(*index)++] = n;
    if (n == 1)
        return;
    syracuse(collatz(n), squence, index);
}
//print the stock
void print(int *array, int size)
{
    printf("\n Direct:\n");
    for (int i = 0; i < size; i++)
        printf("%i\t", array[size - 1 - i]);
    printf("\n Indirect:\n");
    for (int i = 0; i < size; i++)
        printf("%i\t", array[i]);
    printf("\n");
}
int main()
{
    int n = 28, index = 0;
    int *tab = (int *)malloc(compter(n) * sizeof(int));
    syracuse(n, tab, &index);
    print(tab,index);
    // printf("\n\t%i", max_collatz(n));
}