//string reversal
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(char str[])
{
    int i=0;
    int len=strlen(str);
    char temp;
    for(i=0;i<(len)/2;i++)
    {
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
void inplacerev(char str[])
{
    int i=0,j=0,start=0,end=0;
    int len=strlen(str);
    char temp;
     for (i = 0; i <= len; i++) { 
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') { 
            end = i - 1; 
            for (j = 0; start + j < end - j; j++) {
                temp = str[start + j];
                str[start + j] = str[end - j];
                str[end - j] = temp;
            }
            start = i + 1; 
        }
    }
}

int main()
{
    char str[50]="My name is sanjana";
    printf("Original string:%s\n",str);
    reverse(str);
    inplacerev(str);
    printf("Reversed string:%s\n",str);
    return 0;
}
