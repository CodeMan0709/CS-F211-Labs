
#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000000], pat[1000000];
    gets(str);
    gets(pat);

    int len1 = strlen(str);
    int len2 = strlen(pat);

    int arr1[26];
    int arr2[26];
    
    for(int i=0;i<len1;i++)
    {
        arr1[i]=0;
    }

    for(int i=0;i<len2;i++)
    {
        arr2[i]=0;
    }

    for(int i=0;i<len1;i++)
    {
        arr1[str[i]]++;
    }

    for(int i=0;i<len2;i++)
    {
        arr2[pat[i]]++;
    }

    int a=0;
    int start=0;
    int b=-1;
    int len =9999;

    for(int left=0;left<len1;left++)
    {
        if(arr2[str[left]] != 0 && arr1[str[left]]<=arr2[str[left]])
        a++;

        if(a==len2)
        {
            while(arr1[str[start]]>arr2[str[start]] || arr2[str[start]]==0)
            {
                if(arr1[str[start]]>arr2[str[start]])
                {
                    arr1[str[start]]--;
                }

                start++;
            }
            
        }
    }
}