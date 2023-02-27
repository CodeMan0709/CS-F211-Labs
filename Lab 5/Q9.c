#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    int oddCount=0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]%2==1)
        {
            oddCount++;
        }
    }

    int odd[oddCount];

    int j=0; 
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==1)
        {
            odd[j++]=i;
        }
    }

    int ans =0;
    for(int i=0;i<=oddCount-k;i++)
    {
        int temp = i + k -1; 
        int start = odd[i];
        int end = -odd[temp];

        if(i==0)
        {
            start++;
        }
        else
        {
            start = start - odd[i-1];
        }

        if(temp == oddCount-1)
        {
            end = end+n;
        }
        else
        {
            end = end + odd[temp+1];
        }

        ans = ans + start*end;
    }

    printf("%d", ans);
}