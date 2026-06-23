#include<stdio.h>

int main()
{
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int sumOfTwoArray[sizeof(arr1)/sizeof(arr1[0])];
    int arraySum;

    printf("arraySum:");
    for(int i = 0; i<=n-1; i++)
    {
         sumOfTwoArray[i] = arr1[i] + arr2[i];
            printf(" %d",sumOfTwoArray[i]);

    }

    printf("\n---------------------------\n");

    for(int i = 0; i <= n-1; i++)
    {
        arraySum += arr1[i];
    }

    printf("arraySum: %d", arraySum);

    return 0;
}