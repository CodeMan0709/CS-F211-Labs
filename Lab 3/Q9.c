#include <stdio.h>

// long long int mid(long long int n)
// {
//     long long int left = 1, right = n;
//     long long int mid = (left) + (right - left) / 2;

//     while (left <= right)
//     {
//         mid = (left) + (right - left) / 2;
//         long long int comparisons = (n - mid) * (n - mid - 1) / 2;
//         if (comparisons == (n * (n - 1) / 2) / 2)
//         {
//             return mid;
//         }
//         else if (left + 1 == right)
//         {
//             return left;
//         }
//         else if (comparisons < (n * (n - 1) / 2) / 2)
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

long long int comp(long long int n,long long int m)
{
    long long int comparison = m*n - ((n)*(n+1))/2;
    // printf("%d \n",comparison);
    return comparison;
}
long long int steps(long long int n)
{
    long long int left=0;
    long long int right =n;
    long long int mid = left+(right-left)/2;
    long long int target=(n*(n-1))/4;
    long long int ans = 0;
    long long int tempmid = comp(mid,n);

    while(left<=right)
    {
        if(tempmid>=target)
        {
            ans = mid;
            right=mid-1;  
        }
        else
        {
            left=mid+1;
        }
        mid = left+(right-left)/2;
        tempmid=comp(mid,n);

    }
    return ans;
}

int main()
{
    long long int n;
    scanf("%lld", &n);

    long long int ans = steps(n);
    printf("%lld", ans);
    return 0;
}