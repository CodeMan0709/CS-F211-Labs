#include <stdio.h>
#include <stdlib.h>

typedef struct hehe
{
    char name[20];
    int gold;
    int silver;
    int bronze;
} medal;

void swap(medal *country[], int a, int b)
{
    medal *temp = country[a];
    country[a] = country[b];
    country[b] = temp;
}

// void swap2(medal *country[], medal **a, medal **b)
// {
//     medal ** temp =a;
//     a=b;
//     b=temp;
// }

int main()
{
    int n;
    scanf("%d", &n);
    medal *country[n];
    for (int i = 0; i < n; i++)
    {
        medal *med = malloc(1 * sizeof(medal));
        country[i] = med;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &country[i]->name);
        scanf("%d", &country[i]->gold);
        scanf("%d", &country[i]->silver);
        scanf("%d", &country[i]->bronze);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1 ; j++)
        {
            if (country[j]->gold < country[j+1]->gold)
            {
                // swap2(country,&country[j],&country[j+1]);
                swap(country,j,j+1);
            }
        }
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1 ; j++)
        {
            if(country[j]->gold == country[j+1]->gold)
            {
                if(country[j]->silver < country[j+1]->silver)
                {
                    swap(country,j,j+1);
                }
            }
        }
    } 

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1 ; j++)
        {
            if(country[j]->gold == country[j+1]->gold)
            {
                if(country[j]->silver == country[j+1]->silver)
                {
                    if(country[j]->bronze < country[j+1]->bronze)
                    {
                        swap(country,j,j+1);
                    }
                }
            }
        }
    } 

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%s ", country[i]->name);
    }
}