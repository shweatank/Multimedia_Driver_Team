//Permutation
#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void getpermutation(char *str,int left,int right)
{
    int i;
    if(left==right)
    {
        printf("%s\n",str);
    }
    else
    {
        for(i=left;i<=right;i++)
        {
            swap(&str[left],&str[i]);
            getpermutation(str,left+1,right);
            swap(&str[left],&str[i]);
        }
    }
}
int main()
{
    char str[100];
    printf("Enter string:");
    scanf("%s",str);
    int n=strlen(str);
    printf("Permutations are:\n");
    getpermutation(str,0,n-1);
    return 0;
}
