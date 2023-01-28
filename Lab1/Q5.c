#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[(2 * (n - 1)) + 1][(2 * (n - 1)) + 1];
    int i = 2 * (n - 1);
    int j = 2 * (n - 1);
    int t = n - 1;
    int s = 2 * n * n;
    int f = 0;
    int clk = t;
    for (int a = 0; a < ((2 * (n - 1)) + 1); a++)
    {
        for (int b = 0; b < ((2 * (n - 1)) + 1); b++)
        {
            arr[a][b] = 0;
        }
    }

    arr[2 * (n - 1)][2 * (n - 1)] = 2 * n * n;
    while (clk--)
    {
        if (s == 2)
        {
            f = 1;
            break;
        }
        arr[i][--j] = -1;
        s = s - 2;
        arr[i][--j] = s;
    }

    while (s != 2)
    {

        clk = t;
        while (clk--)
        {
            if (s == 2)
            {
                f = 1;
                break;
            }
            arr[--i][j] = -2;
            s = s - 2;
            arr[--i][j] = s;
        }

        if (f == 1)
        {
            break;
        }

        clk = t;
        while (clk--)
        {
            if (s == 2)
            {
                f = 1;
                break;
            }
            arr[i][++j] = -1;
            s = s - 2;
            arr[i][++j] = s;
        }

        if (f == 1)
        {
            break;
        }
        t--;
        clk = t;
        while (clk--)
        {
            if (s == 2)
            {
                f = 1;
                break;
            }
            arr[++i][j] = -2;
            s = s - 2;
            arr[++i][j] = s;
        }

        if (f == 1)
        {
            break;
        }

        clk = t;
        while (clk--)
        {
            if (s == 2)
            {
                f = 1;
                break;
            }
            arr[i][--j] = -1;
            s = s - 2;
            arr[i][--j] = s;
        }

        if (f == 1)
        {
            break;
        }
        t--;
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (arr[i][j] == -1)
            {
                printf("--  ");
            }
            else if (arr[i][j] == -2)
            {
                printf("|   ");
            }
            else if (arr[i][j] == 0)
            {
                printf("    ");
            }
            else
            {
                printf("%d  ", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}