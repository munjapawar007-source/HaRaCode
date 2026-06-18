/*
Q3. Write a program which takes a year as input and check whether it is leap year or not.

Input: 2000
Output: True.

Input: 2013
Output: False.

Author: Munja
*/

#include<iostream>
using namespace std;

bool leapYear(int year)
{
    if(year % 4 != 0 || year % 400 != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    int year;
    cout << "Enter year: ";
    cin >> year ;
    cout << endl;

    if(leapYear(year))
        cout << "It is a leap year" << endl;
    else
        cout << "It is not a leap year" << endl;

    return 0;
    
}