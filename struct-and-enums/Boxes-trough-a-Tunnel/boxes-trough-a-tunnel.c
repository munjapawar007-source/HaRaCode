#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 41

struct Box
{
    int length, width, height;
};

typedef struct Box box;

int get_volume(box b)
{
    int box_volume = 0;
    box_volume = b.length * b.width * b.height;
    return box_volume;
}

int is_lower_than_max_height(box b)
{
    return b.height < MAX_HEIGHT;
       
}

int main(void)
{
    int n;
    puts("Enter the number of boxes:");
    scanf("%d", &n);

    box *boxes = (box*)malloc(n * sizeof(box));
    for(int i = 0; i < n; i++)
    {
        puts("enter the box size(L,W,H):");
        scanf("%d,%d,%d",&boxes[i].length, &boxes[i].width, &boxes[i].height);
    }

    for(int i = 0; i < n; i++)
    {
        if(is_lower_than_max_height(boxes[i]))
        {
            printf("%d\n", get_volume(boxes[i]));
        }
    }

    free(boxes);
    boxes = NULL;
    return 0;
}