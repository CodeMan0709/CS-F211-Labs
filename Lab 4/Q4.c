#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000005

int n, q;
int primes[MAX_N];
char is_prime[MAX_N]; // 0 = not prime, 1 = prime

// prime sieve
void sieve()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    int p = 2;
    while (p * p <= n)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = 0;
            }
        }
        p++;
    }
}

int main()
{
    scanf("%d %d", &n, &q);

    // generate primes
    sieve();
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes[count++] = i;
        }
    }

    // answer queries
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = count - 1, m, ans = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (primes[m] <= x)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        printf("%d ", ans + 1);
    }
    printf("\n");

    return 0;
}
