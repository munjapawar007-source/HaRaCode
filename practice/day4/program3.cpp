/*
Q3. Write a program which accept N number from the user and return smallest number from it.

Input: 5
Input: 10 20 30 40 50
Output: 10

Input: 6
Input: 85 69 21 45 73 25
Output: 21

Author: munja
*/

#include<iostream>
#include<vector>
using namespace std;

int smallest_number(int nums)
{

    vector<int> arr;
    int element, smallest_num;
    cout << "push value into the vector: ";

    for(int i = 0; i < nums; i++)
    {
        cin >> element;
        arr.push_back(element);

        if(i == 0)
            smallest_num = arr[0];

        if(arr[i] < smallest_num)
        {
            smallest_num = arr[i];
        }
    }

    return smallest_num;
}

int main()
{
    int n;
    cout << "enter vector len: ";
    cin >> n;
    cout << endl;
    cout << "smallest num: " << smallest_number(n) << endl;

    return 0;
}
