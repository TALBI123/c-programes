#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char to_char(int a)
{
    if(a>=0 && a<=9)
        return (char)(a + (int)'0');
    return -1;
}
int count_digit(int n)
{
    return n==0 ? 1 : 1 + count_digit(n/10);
}
char *number_to_char(int n)
{   //sizeof(char) == 1
    printf("%i\n",count_digit(n));
    bool is_negative = n<0;
    char *digit = (char *) malloc(count_digit(n)+1);
    if(digit==NULL) return NULL;
    char *ptr = digit + count_digit(n);
    *ptr = '\0';
    ptr--;
    if(n==0)
    {
        *ptr = '0';
        return digit;
    }
    n = n<0 ? -n : n;
    while(n!=0)
    {
        *(ptr--) = to_char(n%10);
        n/=10;
    }
    if(is_negative) *ptr = '-';
    return is_negative ? ptr : ptr+1;
}
int main()
{
    int number = -6754;
    char *dig = (char *) number_to_char(number);
    for(int i = 0;i<count_digit(number);i++)
        printf("T[%i]:%c\n",i,*dig++);
}