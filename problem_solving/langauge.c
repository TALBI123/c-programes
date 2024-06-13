#include <stdio.h>
// Write a C program to determine 
// if a given number is an Armstrong
// number.
int num_digit(int n)
{//this function calculate number of digit
    return n/10==0 ? 1 : 1 + num_digit(n/10);
}
//this function is working if y>0 if y<0 this
int powp(int x,int y)
{//this function if y<0 is repeated infinite time
    return y==0 ? 1 : x*powp(x,y-1);
}
int arm(int n1,int n2)
{
    if(n2==0)
        return 0;
    return powp(n2%10,num_digit(n1)) + arm(n1,n2/10);
}
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%i",&n);
    if(arm(n,n) != n)
        printf("\t%i is not armstrong",arm(n,n));
    else
    printf("\t%i is an armstrong",arm(n,n));
//because 153 = 1*1*1 + 5*5*5 + 3*3*3
}