#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end,int *ans)
{
    int len1 = mid-start+1;
    int len2 = end-mid;

    int a[len1];
    int b[len2];

    for(int i=0;i<len1;i++)
    {
        a[i]=arr[start+i];
    }

    for(int i=0;i<len2;i++)
    {
        b[i]=arr[mid+i+1];
    }

    int l=0,r=0,k=start;

    while(l<len1 && r<len2)
    {
        if(a[l]<=b[r])
        {
            arr[k]=a[l];
            k++;
            l++;
        }
        else if(a[l] > b[r])
        {
            arr[k]=b[r];
            k++;
            r++;
            (*ans)+=r-l;
        }
    }

    while(l<len1)
    {
        arr[k]=a[l];
        k++;
        l++;
    }
    while(r<len2)
    {
        arr[k]=b[r];
        k++;
        r++;
    }
}

void mergeSort(int arr[],int left,int right,int* ans)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(arr,left,mid,ans);
        mergeSort(arr,mid+1,right,ans);
        merge(arr,left,mid,right,ans);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans=0;
    mergeSort(arr,0,n,&ans);
    cout<<ans;

    return 0;
}