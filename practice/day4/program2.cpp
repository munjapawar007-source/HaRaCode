/*
Q2. Write a program which accept range from user and return addition of all even numbers in between that range.
 (Range should contains positive numbers only)

Input : 23 30
Output : 108

Input : -10 2
Output : Invalid range

Input : 90 18
Output : Invalid range

Author: munja
*/

#include <iostream>
using namespace std;

int addition_of_even_number(int num_from, int num_to);

int main()
{
    int val1, val2;
    cout << "Enter start range: ";
    cin >> val1;
    cout << "Enter End range: ";
    cin >> val2;

    cout << "sum of even numbers: " << addition_of_even_number(val1, val2) << endl;

    return 0;
}

int addition_of_even_number(int num_from, int num_to)
{

    int sum = 0;

    for (int j = num_from; j <= num_to; j++)
    {
        if (j % 2 == 0)
        {
            sum += j;
            // cout << j << " ";
        }
    }
    return sum;
}

