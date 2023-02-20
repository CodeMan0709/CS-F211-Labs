#include <stdio.h>
#include <math.h>

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int is_coprime(long long int a, long long int b)
{
    if (gcd(a, b) == 1)
        return 1;
    else
        return 0;
}

long long int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    
    long long int max_divisor = 1;
    for (long long int i = sqrt(a); i * i > 1; i--)
    {
        if (a % i == 0)
        {
            if (is_coprime(i, b))
            {
                max_divisor = i;
                break;
            }
        }
    }
    for (long long int i = sqrt(a); i * i >= 1; i--)
    {
        if (is_coprime(a / i, b) && (a%i == 0))
        {
            max_divisor = a/i;
        }
    }

    printf("%lld", max_divisor);

    return 0;
}
