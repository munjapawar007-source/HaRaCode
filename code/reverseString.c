#include<stdio.h>
#include<string.h>
int main()
{
    int palindrome;
    int temp;
    // printf("palindrome: ");
    // scanf("%d",&palindrome);

    char str[] = "i am a man";
    char str1[sizeof(str)/sizeof(str[0])];
    temp = sizeof(str)/sizeof(str[0]);

    for(int i = 0; i <= temp-1; i++)
    {
        str1[i] =str[temp - 1 - i]; 
        printf("%c",str1[i]);
    }
    printf("\n%d",sizeof(str1));


}
