/*
Q1. Write a program which accept number from the user and return the addition digits.
Input: 3458
Output: 20

Input: 52
Output: 7

Author: munja
*/

#include<iostream>
using namespace std;

int sumOfDigit(int a)
{
   int sum = 0;
    while (a != 0)
    {
        sum += a % 10;  // provide last digit
        a /= 10;        // chop last digit
    }
    
    return sum;
}

int main()
{
    int a;
    cout << "a: ";
    cin >> a; 
    cout << endl;

    cout << "sum of digit = " << sumOfDigit(a) << endl;
}
