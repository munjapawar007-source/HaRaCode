/*
Q1. Write a program which accept N number from the user and return the average.

Input: 5
Input: 10 20 30 40 50
Output: 30

Input: 6
Input: 85 69 21 45 73 25
Output: 53

Author: munja
*/

#include<iostream>
#include<vector>
using namespace std;

int average(vector<int> nums);

int main() 
{
      int n, element;
    vector<int> nums;
    cout << "Enter n Number Count:";
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> element;
        nums.push_back(element);
    }

    cout << average(nums) << endl;;

    return 0;
}

int average(vector<int>nums)
{
    int sum = 0;
    for(int ele : nums)
    {
        sum += ele;
    }

    return sum/nums.size();
}

