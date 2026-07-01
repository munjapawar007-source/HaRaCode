/*
Q.2 Program to print the elements of an array in reverse order

Input:
arr = [1, 2, 3, 4, 5]

Output:
Original array: 1 2 3 4 5
Array in reverse order: 5 4 3 2 1

Author: munja
*/

#include<iostream>
using namespace std;

class Array
{
    int *arr;
    int n;

    public:
     Array() : arr(NULL), n(0){}

     Array (int n)
     {
        arr = new int[n];
        this->n = n;
     }

     void accept();
     void display();
     int *reverse();

     private:
     void swap(int* a, int *b);
};

void Array::swap(int *a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Array::display()
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::accept()
{
    int i;
    cout << "Enter the data: ";

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

}

int *Array::reverse()
{
    int i = 0, j = n - 1;

    while(i < j)
        swap(&arr[i++], &arr[j--]);
    
    return arr;
}

int main()
{
    int n;
    
    cout << "Enter the number of element: ";
    cin >> n;

    Array obj(n);

    obj.accept();
    cout << "Original Array: ";
    obj.display();
    obj.reverse();
    cout << "Array in reverse order: ";
    obj.display();

    return 0;

}