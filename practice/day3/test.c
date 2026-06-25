#include<stdio.h>

int main()
{
    int fun(void);
    int ans;

    ans = fun();
    printf("%d",ans);

    return 0;
}

int fun(void)
{
    printf("hello");   
}

// what will ans print
// ans = hello5
// 5 bcoz printf return type is 5
// 