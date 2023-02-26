#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d\n", &n, &k);
    char arr[n];


    for (int i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    int freq[26];

    for (int i = 0; i < k; i++)
    {
        freq[i] = 0;
    }

    int ans = 0;
    int i = 0;
    int j = 0;
    int check = 0;
    freq[arr[0]-'a']++;

    while (j < n)
    {

        int temp = 0;
        check=1;

        while (temp < k)
        {
            if (freq[temp] == 0)
            {
                check = 0;
                break;
            }
            temp++;
        }

        if (check == 1)
        {
            ans+= n - j;
            freq[arr[i] - 'a']--;
            i++;
        }
        else
        {
            j++;
            freq[arr[j] - 'a']++;
        }
    }

    printf("%d", ans);
}