#include<stdio.h>

void bitShift(int n)
{
    for(int i = 3; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        printf("%d",bit);
    }
}
int main()
{
    int n = 10;
    bitShift(n);

}