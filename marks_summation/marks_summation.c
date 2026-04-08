#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int marks_sumation(int* marks, int numbers_of_students, char gender)
{
    int sum = 0;

    if(gender == 'b')
    {
        for(int boys = 0; boys < numbers_of_students; boys += 2)
        {
            sum += marks[boys];
        }
    }

    if(gender == 'g')
    {
        for(int girls = 1; girls < numbers_of_students; girls += 2)
        {
            sum += marks[girls];
        }
    }

    return sum;
}

int main(void)
{
    int number_of_students;
    char gender;
    int sum;

    scanf("%d", &number_of_students);
    int *marks = (int*)malloc(number_of_students * sizeof(int));

    for(int student = 0; student < number_of_students; student++)
    {
        scanf("%d",(marks+student));
    }

    getchar();  //reads one character from the input stream (keyboard).
    printf("Enter gender(b/g):");
    scanf("%c", &gender);   // if u dont use getchar() for clear buffer 
                            // then %c read whitespace and its read \n newline char
                            // or you can use 2 space befor %c
    sum = marks_sumation(marks, number_of_students,gender);
    printf("%d",sum);
    free(marks);

    return 0;
}