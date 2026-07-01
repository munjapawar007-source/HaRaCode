/*
Q3. Write a Program for Printing Incrementing Number Square Pattern.

Input : row = 4, col = 6
Output:

1 1 1 1 1 1 
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4

Author: munja
*/

#include <iostream>
using namespace std;

void number_pattern(int row, int col);

int main()
{
    int row;
    int col;

    cout << "row: ";
    cin >> row;
    cout << "col: ";
    cin >> col;
    cout << endl;

    number_pattern(row, col);

    return 0;
}

void number_pattern(int row, int col)
{

    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            cout << i << " "; 
        }
        cout << endl;
    }
    
}