#include<stdio.h>
#include<string.h>

void rev(char* arr,int left,int right)
{
    char temp;
    while(left<right)
    {
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;

    }
}

int main()
{
    char str[100];
    char copy[100];
    gets(str);
    strcpy(copy,str);
    int l=strlen(str);
    
    int start=0,end=0;
    for(int i=0;i<=l;i++)
    {
        if((str[i]==' ') || (str[i]==0))
        {
            end=i;
            rev(str,start,end-1);
            start=end+1;
        }
    }
    puts(str);
    start=0;
    end=1;
    int first=1;
    int check=1;
    
    for(int i=0;i<=l;i++)
    {
        if((str[i]==' ') || (str[i]==0))
        {
            start=i+1;
            int j=start;
            while(str[j]!= ' ' && (str[j]!=0))
            {
                if(str[j]!=copy[j])
                {
                end=0;
                break;
                }
                j++;
            }   
            if(end)
            {
            j=start;
            while(str[j]!= ' ' && (str[j]!=0))
            {
                printf("%c",copy[j]);
                check=0;
                j++;
            }
            printf(" ");
            }
            end=1;
        }
        
    }
    if(check)
    printf("No Palindromes");

    return 0;


}