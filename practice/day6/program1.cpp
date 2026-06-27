/*
Q.1 Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 6, col = 6
Output :

*   *   *   *   *   *   
*   *               *
*       *           *
*           *       *
*               *   *
*   *   *   *   *   *

Author: munja
*/

#include<iostream>
using namespace std;

void pattern(int row, int col);

int main()
{
    int row,col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter colunm: ";
    cin >> col;

    pattern(row,col);

    return 0;
}

void pattern(int row, int col)
{

    if (row != col)
        return;
        
    for(int i = 1; i <= row; i++)
    {
        
        for(int j = 1; j <= col; j++)
        {
            
            if(i == 1 || j == 1 || i == row || j == col || row == col)
            cout << "* ";
            else
            cout << "   ";   

        }
        cout << endl;

    }
    

}