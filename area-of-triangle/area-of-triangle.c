#include<stdio.h>
#include<math.h>

void area_of_triangle(void);

int main(void)
{
    area_of_triangle();

    return 0;
}

void area_of_triangle(void)
{
    //veriable declarations
    double s1, s2, s3;

    //code
    // take side value from user
    printf("Enter value for s1:");
    scanf("%lf",&s1);

    printf("Enter value for s2:");
    scanf("%lf",&s2);

    printf("Enter value for s3:");
    scanf("%lf",&s3);

    // check validation
    if((s1<=0.0) || (s2<=0.0) || (s3<=0.0))
    {
        fprintf(stderr,"bad input, side of triangle can not be negative\n");
    }

    // check sum of any two sides of triangle is grether than that of the third side
    if((s1 + s2 <= s3) || (s2 + s3<= s1) || (s3 + s1 <= s2))
    {
        fprintf(stderr,"given measures of side do not from triangle\n");
        fprintf(stderr,"voilation:sum of two sides of triangle is grether than that the thired\n");
    }

    printf("s1:%.3lf, s2:%.3lf, s3:%.3lf\n", s1, s2, s3);

    // perimeter and semi-perimeter of triangel
    double p; // for perimeter
    double s; // for semi-perimeter

    p = s1 + s2 + s3;
    s = p / 2.0;

    printf("perimeter:%.3lf unit\nsemi-perimeter:%.3lf unit\n", p, s);

    // area of triangle 
    double a; // for area

    a = sqrt(s * (s - s1) * (s - s2) * (s - s3));
    printf("area of triangle: %.3lf", a);

}
