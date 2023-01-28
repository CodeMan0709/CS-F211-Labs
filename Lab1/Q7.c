#include<stdio.h>
#include<string.h>

int main()
{
    char str[100000];
    char test[100000];
    gets(str);
    gets(test);

    int arr [26];

    for(int i=0;i<26;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<26;i++)
    {
        arr[test[i]-'a']++;
    }

    int start,end=0;
    int s=strlen(str);
    int temp=strlen(test);

    while(end<s)
    {
        char endchar = str[end];

        if()
    }
}