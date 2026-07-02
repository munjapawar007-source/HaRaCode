/*
Q.1 Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 7, col = 7
Output :
         *
        *  *
      *  *  *
     *  *  *  *
   *  *  *  *  *
  *  *  *  *  *  *
*  *  *  *  *  *  *

Author: munja
*/

#include<iostream>
using namespace std;

void pattern(int n);

int main(void)
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    pattern(n);

    return 0;
}

void pattern(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n; col++)
        {
            if(col > row)
                cout << " *";
            else //if(row < col)
                cout << " ";
        }
        cout << endl;
    }
}