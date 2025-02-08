//string reversal 2
#include<stdio.h>
#include<string.h>
void inplace_reverse(char *str)
{
    int i=0,j=0,start=0,end=0;
    char temp;
    int len=strlen(str);
    while(i<=len)
    {
        if(str[i]==' '||str[i]=='\0'||str[i]=='\n')
        {
            end=i-1;
            for(j=start;j<end;j++)
            {
                temp=str[start];
                str[start]=str[end];
                str[end]=temp;
                start++;
                end--;
            }
            start=0;
            start=start+i+1;
        }
        i++;
    }
    
}
int main()
{
    char str[50]="Sanjana Sharma";
    printf("Original string:%s\n",str);
    inplace_reverse(str);
    printf("In wor reversal of string:%s\n",str);
    return 0;
}
