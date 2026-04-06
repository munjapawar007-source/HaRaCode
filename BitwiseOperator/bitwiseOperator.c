#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) 
{
  //Write your code here.
  int maxAND = 0;
  int maxOR = 0;
  int maxXOR = 0;
  int and = 0, or = 0, xor = 0;
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
        and = i & j;  
        if(and > maxAND && and < k)
        {   
            maxAND = and;
            //printf("maxAnd=%d ",maxAND);
        }
        
        or = i | j;
        if(or > maxOR && or < k)
        { 
            maxOR = or;
           //printf("maxOR=%d ",maxOR);
        }
        
        xor = i^j; 
        if(xor > maxXOR && xor < k)
        {
            maxXOR = xor;
            //printf("maxXOR=%d\n",maxXOR);
        }
    }
    
  }
  
  printf("%d\n",maxAND);
  printf("%d\n",maxOR);
  printf("%d\n",maxXOR);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
