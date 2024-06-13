#include <stdio.h>
#include <stdlib.h>
// The program breaks down n into its prime factors
int main()
{
   int n,n2,count = 0;
   printf("choose a number:");
   scanf("%i",&n);
   n2 = n,count = 0;
   for(int i=2;i<n2;i++)
   {
        if(n%i == 0)
        {
            n /= i--;
            count++;
            if(n == 0)
                break;
        }
   }
   int *array = (int *) malloc(count*sizeof(int));
   count = 0,n = n2;
   for(int i=2;i<n2;i++)
   {
        if(n%i == 0)
        {
            n /= i;
            array[count++] = i--;
            if(n == 0)
                break;
        }
   }
   for(int i=0;i<count;i++)
   {
        if(i != count - 1)
            printf("%i * ",array[i]);
        else
            printf("%i = ",array[i]);
   }
   printf("%i",n2);
 
}