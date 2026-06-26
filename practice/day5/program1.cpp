/*
Q1. Write a program which accept N numbers from user and display addition of digits of each element.

Input: 5
Input: 85 36 98 125 225
Output: 13 9 17 8 9

Input: 7
Input: 854 698 236 14 75 32 65
Output: 17 23 14 5 12 5 11

Author: munja
*/

#include <iostream>
#include <vector>
using namespace std;

void addition_of_digit(int n);

int main()
{
    int n;
    cout << "Enter how many element do you want: ";
    cin >> n;

    addition_of_digit(n);

    return 0;
}

void addition_of_digit(int n)
{
    int element;
    vector<int> arr;
    cout << "push element in array: ";
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    cout << "sum of each digit: ";
    for (int i = 0; i <= n - 1; i++)
    {
        int digit = 0;
        int ele = arr[i];
        while (ele != 0)
        {
            digit += arr[i] % 10;
            arr[i] /= 10;
        }
        cout << digit << " ";
    }

    cout << endl;
}