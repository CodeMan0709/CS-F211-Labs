#include <stdio.h>

long long int mid(long long int n)
{
    long long int left = 0, right = (n*(n - 1))/2;
    long long int mid = (left) + (right - left) / 2;

    while (left <= right)
    {
        // mid = (left) + (right - left) / 2;
        long long int comparisons = mid * (n - mid - 1) / 2;
        if (comparisons == (n * (n - 1) / 2) / 2)
        {
            return mid + 1;
        }
        else if (comparisons < (n * (n - 1) / 2) / 2)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    long long int n;
    scanf("%lld", &n);

    long long int ans = mid(n);
    printf("%lld", ans);
    return 0;
}