#include<stdio.h>

int main()
{
    int arr[] = {7,3,4,9,22,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp = arr[0];  // arr 0th index is largest

    for(int i = 1; i <= n-1; i++)
    {
        if(arr[i] >= temp)      // logic for largest number
        {
            temp = arr[i];
          
        }
    }

    printf("\nLargest Number:%d\n", temp);

    return 0;
}

