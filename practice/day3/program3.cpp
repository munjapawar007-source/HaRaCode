/*
Q3. Write a program to find factorial of input number.

Input: 5
Output: 120

Input: 4
Output: 24'

Author: munja
*/

#include<iostream>
using namespace std;

int factorial_of_n_number(int n)
{
    if( n == 0 || n == 1)
        return n = 1;
  
    return n * factorial_of_n_number(n - 1);  
}

int factorial(int n)
{
    int factorial = 1;
    if (n == 0 || n == 1)
        return n = 1;
    
       for(int i = 1; i <= n; i++)
        {
            factorial *= i;
        }
    return factorial;
}

int main()
{
    int n;
    cout << "Enter the number whose factorial you want to calculate: ";
    cin >> n;

    cout << "factorial number using recursion: " << factorial_of_n_number(n) << endl;
    cout << "factorial number using Loop: " << factorial(n) << endl;

    return 0;
}