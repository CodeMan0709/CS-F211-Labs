#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long king, room;
    scanf("%lld %lld", &king, &room);

    long long max, min;

    max = (king - room + 1) * (king - room) / 2 + room - 1;

    long long k = king / room;
    long long rem = king % room;
    
    min = rem * (k + 1) * k / 2 + (room - rem) * k * (k - 1) / 2;

    printf("%lld %lld\n", min, max);

    return 0;
}
