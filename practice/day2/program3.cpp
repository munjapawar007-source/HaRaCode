/*
Q3. Write a function that reverses a string..
Input: MUNJA
Output: AJNUM

Input: COOL
Output: LOOC.

Author: munja
*/

#include<iostream>
#include<string>
using namespace std;

void reverseString(string &str)
{   
    int n = str.length();
    for(int i = n-1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}
int main()
{
    string str = "MUNJA";
    
    reverseString(str);
    
    return 0;
}
