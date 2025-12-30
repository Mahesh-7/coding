#include <stdio.h>

int a[]={1,2,3,4,5};

char * name [] = {"mahesh","ram"};

int main()
{
    // 1.pointer to array
    int  (*p1)[5] = &a; // int 
    int i;
    for(i=0;i<5;i++)
    {
        //printf("%d ",*(*p1+i));
        printf("%d ",(*p1)[i]);
    }

    char *(*p2)[2] =&name; // string
    for(i=0;i<2;i++)
    {
        printf("%s ",(*p2)[i]);
    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // 2.array of pointers
    int * p3[5] = {&a[0],&a[1],&a[2],&a[3],&a[4]}; // int 
    for(i=0;i<5;i++)
    {
        printf("%d ",*p3[i]);
    }

    char * p4[2] = {name[0],name[1]}; // string -> no need to use address symbol since its already pointing base address.
    for(i=0;i<2;i++)
    {
        printf("%s ",p4[i]);
    }

    return 0;
}