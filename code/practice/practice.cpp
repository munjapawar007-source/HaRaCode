#include<stdio.h>

void recursion(int count) {
    int local_var = 10;   // har veli 4 bytes stack madhe
    if(count == 0) return;
    printf("Calling...\n");
    recursion(count - 1);   // jr recursion(count) kel tr infinite recursion — kadhi nahi thambat!
                            // stack Overflow hoil
}


int main()
{
     
    float a = 3.5e38; double b = 3.5e307;
    //recursion(a);
   // a = 2*3+4%5-3/2+6;  // 15
   // printf("a:%d%d%d%d\n",6/5,-6/5,6/-5,-6/-5); // ans = 1-1-11 follow regular math rule Trunacation(kapun takane in prog/math lang) (.1 point ntr chi sakhya kadhane)
   // printf("a:%d%d%d%d\n",6%5,-6%5,6%-5,-6%-5); // ans = 1-11-1 follow c-99 sign rule(use 1st number sign)
    //printf("b:%d,b:%d", b, b=a); // trap 
    //printf("%d%d%d%d",72,0721,0x721,0X721); // 072 he octal num ahe (octal num chi suruvata 0 ne hote)
    //printf("%d%o%x",72,72,72);
   // printf("%i%i%i%i",72,072,0x72,0X72);      // same as %d
   //printf("%6.3f,%06.3f,%09.3f,%-09.3f,%6.0f,%6.0f", 45.6f, 45.6f, 45.6f, 45.6f, 45.6f, 45.6f); // 0 ne padding karta ye
                                                                                                    // 0 use kela tr num chya agodr 0 ne padding hote
                                                                                                    // - use kel tr num chya ntr
   // printf("c:cm\\bin");

   int f_age = 40, s_age = 10;
   int diff = f_age - s_age;
   int twice_age_of_father = f_age + s_age + diff;

   printf("Father age =%d",twice_age_of_father);

    
}