//Write a program where a function sum(int, int) takes two integers and returns their sum. Declare a function pointer to call this function.
#include<stdio.h>
int add(int x,int y)
{
    return x+y;
    
}
int main()
{
    int (*fp)(int,int)=add;
    printf("Sum is:%d",fp(10,5));
    return 0;
}
