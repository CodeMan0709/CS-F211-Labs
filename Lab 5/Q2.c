#include<stdio.h>

long long int findPos(long long int n)
{
    if(n==1)
    return 1;

    else
    {
        int a = (n/2)*2- findPos(n/2)+1;
        return a;
    }


    
}

// if (n == 1) {
//         return 1;
//     } else if (n % 2 == 0) {
//         return 2 * (n / 2) - findSurvivorPosition(n / 2) + 1;
//     } else {
//         return 2 * ((n - 1) / 2) + 1 - findSurvivorPosition(n / 2);
//     }
int main()
{
    long long int n;
    scanf("%lld",&n);

    long long int ans = findPos(n);
    printf("%lld",ans);
    
}