#include<stdio.h>

typedef char*(*fPtr)(char *, const char *);

fPtr funPtr[3];

char* my_strcpy(char *d, const char *s) {
    while((*d++ = *s++));
    return d;
}

int main()
{
    char *a ="mahesh";
    char b[10];
    funPtr[0] =  my_strcpy;
    funPtr[0](b,a);
    printf("string is %s",b);
    return 0;
}