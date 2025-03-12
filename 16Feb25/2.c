//Perform +, -, *, / using function pointers stored in an array.
#include<stdio.h>
int add(int x,int y){return x+y;}
int sub(int x,int y){return x-y;}
int mul(int x,int y){return x*y;}
int divv(int x,int y)
{
	if(y>0)
	{
		return x/y;
	}
	else
		printf("ERROR\n");
}
int main()
{
	int (*op[])(int,int)={add,sub,mul,divv};
	printf("Addition:%d\n",op[0](5,10));
	printf("Difference:%d\n",op[1](10,5));
	printf("Product:%d\n",op[2](5,10));
	printf("Division:%d\n",op[3](10,5));
	return 0;
}
