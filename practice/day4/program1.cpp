/*
Q1. Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 3, col = 5
Output :
5   4   3   2   1
5   4   3   2   1
5   4   3   2   1

Author: Munja
*/

#include<iostream>
#include<vector>
using namespace std;

void pattern(int row, int col);

int main()
{
     int row,col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter col: ");
    scanf("%d", &col);

    pattern(row,col);

    return 0;

}

void pattern( int row,  int col)
{
    int i,j;
   
    for( i = 0; i < row; i++)
    {
        for( j = col; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}