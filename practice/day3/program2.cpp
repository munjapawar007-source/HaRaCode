/*
Q2. Write a program which accept one number from user and print that number of even numbers on screen.

Input : 7
Output: 2 4 6 8 10 12 14

Author: munja
*/

#include<iostream>
using namespace std;

void printEvenNumber(int nums);

int main()
{
    int n;
    cout << "How many even number do you want: ";
    cin >> n;

    printEvenNumber(n);

    return 0;
}

void printEvenNumber(int nums)
{
    int i, j = 1;

    if(nums==0)
        return;
        
    cout << "Even Numbers: ";
    for( i = 1; i <= nums; j++)
    {
        if(j % 2 == 0)
        {
            cout << j << " ";
             i++;
        }
       
    }
    cout << endl;
}


