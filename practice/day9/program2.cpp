/*
Q.2 Program to print the elements of an array present on odd position.

Input: arr = [1, 2, 3, 4, 5]  

Output: Elements of given array present on odd position: 2 4

Author: munja
*/

#include<iostream>
#include <vector>
using namespace std;

void print_even_num(vector<int> num);

int main()
{
    vector<int> n;
    int num;
    cout << "Enter array length: ";
    cin >> num;

    cout << "push element in array: ";
    for(int i = 0; i<num; i++)
    {
        int temp;
        cin >> temp;
        n.push_back(temp);
    }

    print_even_num(n);

    return 0;
}

void print_even_num(vector<int> arr)
{
    // if(arr == 0 || arr == -1)
    //     return;
    
    cout << "\nEven Num: ";
    for(int i = 0; i<arr.size(); i++)
    {
        if(i % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

}
