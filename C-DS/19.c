//Check Endianess
#include<stdio.h>
int main()
{
    int x=1;
    char *c=(char*)&x;
    if(*c==1)
    {
        printf("Little Endian");
    }
    else
    {
        printf("Big Endian\n");
    }
}
