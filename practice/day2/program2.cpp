/*
Q2. Write a program to print given pattern

Input: 5
Output:
*
* *
* * *
* * * *
* * * * *

Author: munja
*/

#include<iostream>
using namespace std;

void starPattern(int a)
{
    char ch = '*';
    for(int i = 0; i < a; i++)
    {
      
        for(int j = 0; j < i; j++)
        {
            cout << ch;

        }
          cout << ch << endl;
    }
}

int main()
{
    int a;
    cout << "Enter Number: ";
    cin >> a;
    cout << endl;

    starPattern(a);
}