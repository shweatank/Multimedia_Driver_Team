//Implement a function operate(int, int, int (*op)(int, int)).
#include<stdio.h>
int add(int x,int y)
{
	return x+y;
}
int operate(int x,int y,int(*fp)(int,int))//function taking function pointer as an argument
{
	return fp(x,y);
}
int main()
{
	printf("Addition%d\n",operate(10,15,add));
	return 0;
}
