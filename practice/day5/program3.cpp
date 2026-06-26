/*
Q3. Write a program which accept two numbers and give their relationship.

Input: 5 -5
Output: 5 is greater than -5

Input: 42 42
Output: Numbers are same

Author: munja

*/

#include<iostream>
using namespace std;

void relation_between_two_num(int no1, int no2);

int main()
{
    int no1, no2;
    cout << "enter No1: ";
    cin >> no1;
    cout << "enter No2: ";
    cin >> no2;
    cout << endl;
    
    relation_between_two_num(no1, no2);

    return 0;
}

void relation_between_two_num(int no1, int no2)
{
    if(no1 > no2)
        cout << no1 << " is greather than " << no2 << endl;
    else if(no1 < no2)
        cout << no1 << " is less than " << no2 << endl;
    else if(no1 == no2)
        cout << "numbers are same" << endl;
}