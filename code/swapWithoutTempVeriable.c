#include<stdio.h>

void swapNumber(int num1, int num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

int main()
{
    int n1,n2;
    printf("n1: ");
    scanf("%d",&n1);
    printf("n2: ");
    scanf("%d",&n2);

    //swapNumber(&n1,&n2);
    int num1 = n1, num2 = n2;
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("after swap n1:%d, n2:%d\n",num1, num2);

}