/*
Q.2 Program to count the total number of punctuation characters exists in a string

Input: char str [] = "Good Morning! Mr. James Potter. Had your breakfast?"  
(If any character in the string is matched with ('!', "," ,"\'" ,";" ,"\"", ".", "-" ,"?"), increment the count by 1.)

Output: Total number of punctuation characters exists in string: 4

Author: munja
*/

#include<iostream>
#include<string>
using namespace std;

int total_punctuation_characters(string str);

int main()
{
    string str = "Good Morning! Mr. James Potter. Had your breakfast?";
    
    cout << total_punctuation_characters(str) << endl;

   
    return 0;
}

int total_punctuation_characters(string str)
{
    int count = 0;
    for(char punctuation : str)
    {
        if (punctuation == '!' || punctuation == ',' || punctuation == '\'' || punctuation == ';' || punctuation == '\"' || punctuation == '.' || punctuation == '-' || punctuation == '?')
            count++;
    }

    return count;
}