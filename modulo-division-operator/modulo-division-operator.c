// Print the sum of the digits of given digit number

#include<stdio.h>
#include<math.h>

int main(void)
{
    int num;
    int sum = 0;

    scanf("%d", &num);

    while(num)
    {
        int remainder = num % 10;  // provide last digit in only this case (10,100,1000...n) 

        sum += remainder;

        num = num / 10;     // remove last digit in only this case(10,100,1000...n)
    }

    printf("addition of total digit is:%d", sum);

    return 0;

}

