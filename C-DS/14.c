//decimal to binary
#include<stdio.h>

void decimal_to_binary(int num)
{
    int binary[32];
    int i=0;
    if(num==0)
    {
        printf("Binary:0\n");
        return;
    }
    while(num>0)
    {
        binary[i]=num%2;
        num=num/2;
        i++;
    }
    printf("Binary:");
    int j;
    for(j=i-1;j>=0;j--)
    {
        printf("%d",binary[j]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter a decimal no.:");
    scanf("%d",&n);
    decimal_to_binary(n);
    return 0;
}
