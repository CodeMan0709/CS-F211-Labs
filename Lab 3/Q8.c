#include <stdio.h>

long long int binarySearch(long long int n)
{
    long long int ans;

    long long int start = 0, end = n;
    long long int mid;

    while (start <= end)
    {
        mid = (start) + (end - start) / 2;

        if(mid>1e9){
            end = mid-1;
            continue;
        }
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        if (mid * mid < n)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    long long int n;
    scanf("%lld", &n);

    long long ans = binarySearch(n);
    printf("%lld",ans);
}
