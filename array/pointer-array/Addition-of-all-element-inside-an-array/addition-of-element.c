#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function declarations
void addition_of_array_elements(void);

int main()
{
    addition_of_array_elements();

    return 0;
}

void addition_of_array_elements(void)
{
    // local veriables
    int index;
    int sum;

    printf("Enter the value of array index:");
    scanf("%d", &index);

    int* arr = (int*)malloc(index * sizeof(int));

    for(int i = 0; i < index; i++)
    {
        printf("fill the array[%d]:", i);
        scanf("%d",&arr[i]);

        sum += arr[i];
    }

    printf("Addition of total element of an array:%d\n", sum);

}
