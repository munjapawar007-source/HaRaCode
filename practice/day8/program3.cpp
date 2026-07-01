/*
Q.3 Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 4, col = 4

Output :
*  *  *  *  
*  #  #  *  
*  #  #  *  
*  *  *  *  

Input : row = 6, col = 6
Output :
*  *  *  *  *  *  
*  #  #  #  #  *  
*  #  +  +  #  *  
*  #  +  +  #  *  
*  #  #  #  #  *  
*  *  *  *  *  * 

Input : row = 8, col = 8
Output :
*  *  *  *  *  *  *  *  
*  #  #  #  #  #  #  *  
*  #  +  +  +  +  #  *  
*  #  +        +  #  *  
*  #  +        +  #  *  
*  #  +  +  +  +  #  *  
*  #  #  #  #  #  #  *  
*  *  *  *  *  *  *  *  

Author: munja
*/

#include<iostream>
using namespace std;

void pattern(int num);

int main()
{
    int num;
    cout << " enter num: ";
    cin >> num;

    pattern(num);
}

void pattern(int num)
{
    for(int row = 1; row <= num; row++)
    {
        for(int col = 1; col <= num; col++)
        {
            if(row == 1 || col == 1 || row == num || col == num)
                cout << "* ";
            else if(row == 2 || col == 2 || row == num - 1 || col == num - 1)
                cout << "# ";
            else if(row == 3 || col == 3 || row == num - 2 || col == num - 2)
                cout << "+ ";
            else
            cout << "  ";
        }
        cout << endl;
    }
}
