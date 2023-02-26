#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectRandom(int x)
{
    static int res;
    static int count = 0;

    count++; // increment count of numbers seen so far

    // If this is the first element from stream, return it
    if (count == 1)
        res = x;
    else
    {
        // Generate a random number from 0 to count - 1
        int i = rand() % count;

        // Replace the prev random number with new number with 1/count probability
        if (i == count - 1)
            res = x;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);
        srand(time(NULL));
        int res = selectRandom(x);
        printf("%d\n", res);
    }
}