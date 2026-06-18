#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i <= n-1; i++)
    {
        cout << arr[i] <<" ";
    }
     cout << endl;
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i <= n-1; i++)
    {
        bool isSwap = false; // check 

        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap)
            return;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i <= n-1; i++)
    { 
        int smallestIdx = i;
        for(int j = i + 1; j <= n - 1; j++)
        {
            if(arr[j] > arr[smallestIdx]) // reverse order taken
            {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]); 
    }
}



int main(void)
{
    int arr[]={1,7,3,8,9,5,6,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    puts("Before sort");
    printArray(arr , n);
    puts("after sort");
    selectionSort(arr, n);
    printArray(arr , n);

            void printBinaryBit(int num)
        {
            for(int i = 3; i >= 0; i--)
            {
                this->bit = (num >> i) & 1;
                cout << "%d" << this->bit;
            }
             cout << endl;
        }

    return 0;
}