/*
Q.1 Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 6, col = 6
Output :

* * * * * * *


* * *

*
* *
*

* * *


* * * * * * *
Author: munja
*/

#include<iostream>
using namespace std;

void print_pattern(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(row == 0 || row == n-1 || col == 0 || col == n-1 || (row + col == n-1))
                cout << "* " ;
            else
            cout << " " << endl; 
        }
    }
    cout << endl;
}

int main()
{
    int n = 0; 
    cout << "num: ";
    cin >> n;


    print_pattern(n);
    
    return 0;
}