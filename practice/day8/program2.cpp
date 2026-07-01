/*
Q.2 Program to print odd number and remove even number

Input: arr = [1, 2, 3, 4, 5]  

Output: Elements of given array present on even position: 1  3  5

Author: munja
*/

#include<iostream>
#include<vector>
using namespace std;

void even_index(vector<int>arr)
{
    for(int j = 0; j<=arr.size(); j++)
    {
        if(j%2 == 0)
        cout << arr[j] << " ";
    }
}

int main()
{
    int num;
    cout << "array size: ";
    cin >> num;

    vector <int> arr;

    cout << "push element into the array: ";
    for(int i = 1; i<= num; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "odd number: ";
     even_index(arr);
    return 0;
}