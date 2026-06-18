/*
Q2. Write a program to count number of digits in given number.
Input: 4365
Output: Number of digits are 4.

Input: 125
Output: Number of digits are 3.

Author: Munja
*/

#include<iostream>
using namespace std;

int count_number_of_digit(int num)
{
    int count = 0;
    while(num)
    {
        count++;
       num = num / 10;
    }
    return count;
}

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << endl;
    cout << "Number of Digit:" << count_number_of_digit(num) << endl;
    
    return 0;
}