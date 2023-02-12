#include <stdio.h>
#include <string.h>
int main()
{
    int test;
    char str[1000000], pat[1000000];
    gets(str);
    gets(pat);

    int len1 = strlen(str);
    int len2 = strlen(pat);

    if (len1 < len2)
    {
        printf("Not Found\n");
    }
    else
    {
        int stri[256] = {0};
        int test[256] = {0};

        for (int i = 0; i < len2; i++)
            test[pat[i]]++;

        int start = 0, start_index = -1, min_len = 9999999;

        int count = 0;
        for (int j = 0; j < len1; j++)
        {
            stri[str[j]]++;

            if (test[str[j]] != 0 &&
                stri[str[j]] <= test[str[j]])
                count++;

            if (count == len2)
            {
                while (stri[str[start]] >test[str[start]] || test[str[start]] == 0)
                {

                    if (stri[str[start]] > test[str[start]])
                        stri[str[start]]--;
                    start++;
                }

                int len_window = j - start + 1;
                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        if (start_index == -1)
            printf("Not Found\n");
        else
        {
            for (int i = start_index; i < min_len + start_index; i++)
                printf("%c", str[i]);
            
        }
    }
}