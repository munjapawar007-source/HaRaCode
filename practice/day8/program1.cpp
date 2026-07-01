/*
Q.1 Write a program which accept rows and numbers of column from user and display below pattern.

Input : row = 7, col = 7

Output :
1)
      *
     * *
    * * *
   * * * *
  * * * * *
  
2)  
    *
    * *
    * * *
    * * * *
    * * * * *

Author: munja
*/


#include<iostream>
using namespace std;

void pattern(int num);

int main()
{
    int num;
    cout << "Enter Num: ";
    cin >> num;
    cout;

    pattern(num);

    return 0;
}

void pattern(int num)
{
    for(int row = 1; row < num; row++)
    {   
       
        // *****for vertical triangle*****
        // for(int col = num; col > 1; col--)
        // {
        //     if(col>row)
        //     cout << " ";
        //     else
        //      cout << " *";
        // }
        //  cout << endl;

        // **** for cross triangle ****
        for(int col = num; col > 1; col--)
        {
            if(col<=row)
    
             cout << "* ";
        }
        cout << endl;

    }
    //cout << endl;
}
