#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[100];

    for(int i = 0; i <= n-1; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i <= n-1; i++)
    {
        if(n == arr[i])
        {
            printf("number is matched\n");

        } 
    }
    return 0;
}