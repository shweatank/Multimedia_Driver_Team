//Palindrome
#include<stdio.h>
#include<string.h>
void is_Palindrome(char *str)
{
    int start=0;
    int end=strlen(str)-1;
    int check=0;
    while(start<end)
    {
        if(str[start]==str[end])
        {
            check=1;
        }
        else
        {
            check=0;
        }
        start++;
        end--;
    }
    if(check==1)
    {
        printf("string is Palindrome\n");
    }
    else
    {
        printf("String is not a Palindrome\n");
    }
}
int main()
{
    char str[20];
    printf("Enter string:");
    scanf("%s",str);
    is_Palindrome(str);
    return 0;
}
