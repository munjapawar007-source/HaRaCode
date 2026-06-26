/*
Q2. Program to find frequency(duplicate element) of each element in array.(Take array elements from user)
Input: arr = [1, 2, 8, 3, 2, 2, 2, 5, 1]

Output:
Element | Frequency
     1  |  2
     2  |  4
     8  |  1
     3  |  1
     5  |  1

Author: munja
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void frequency_of_number(vector<int> n);

int main()
{
    // veriable declaration
    int n, x;
    vector<int> nums;

    cout << "Enter number of element: ";
    cin >> n;

    cou << "Enter data: ";
    for(int i = 0; i<=n-1; i++)
    {
        cin >> x;
        nums.push_back(x);
    }

    frequency_of_number(nums);

    return 0;
}

void frequency_of_number(vector<int> n)
{
    unordered_map<int, int> freq;
    for(int i = 0; i <= n.size(); i++)
    {
        freq[n[i]]++;
    }

    cout << "\nElement  |   frequency\n";
    for(auto pair: freq)
        cout << "   "<<pair.first<<"    "<<pair.second << endl;
}
