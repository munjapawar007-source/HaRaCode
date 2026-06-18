/*
Q1. Write a program which accept number from the user and check whether it is prime or not.
Input: 31
Output: Is is a prime number.

Input: 20
Output: It is not a prime number.

Author: munja
*/

#include<iostream>
using namespace std;

bool check_prime(int num)
{
  
    if(num <= 1)
    return false;

    // for(int i = 2; i * i <= num; i++)
    // {
    //     if(num % i == 0)
    //     {
    //         return false;
    //     }
    // }
        

    /*
    i=2 -> i*i= 4  <= 37 -> 37%2=1  -> go next
    i=3 -> i*i= 9  <= 37 -> 37%3=1  -> go next
    i=4 -> i*i=16  <= 37 -> 37%4=1  -> go next
    i=5 -> i*i=25  <= 37 -> 37%5=2  -> go next
    i=6 -> i*i=36  <= 37 -> 37%6=1  -> go next
    i=7 -> i*i=49  > 37 -> LOOP stop->  is prime  
    */

    // for(int i = 2; i < num; i++)
    // {
    //     if(num % i == 0)
    //         return false;
    // }

    // for(int i = 2; i <= num / 2; i++)
    // {
    //     if(num % i == 0)
    //         return false;
    // }

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    for(int i = 2; i <= num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    for(int i = 2; i = num / 2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int num;
    cout << "Enter Number:";
    cin >> num;
    cout << endl;

    if(check_prime(num))
        cout << "It is prime number\n";
    else
        cout << "it is not prime number" << std::endl;

    return 0;
}