#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct hehe
{
    int person;
    int votes;
} candidate;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void merge(candidate *arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    candidate *L[n1], *R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i]->votes >= R[j]->votes)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(candidate *arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    candidate *arr[n];

    for (int i = 0; i < n; i++)
    {
        candidate *temp = malloc(sizeof(candidate));
        arr[i] = temp;
    }

    int temp[n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
        arr[i]->votes = 0;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]->person = i + 1;
        scanf("%d", &temp[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[temp[i] - 1]->votes++;
    }

    merge_sort(arr, 0, n - 1);


    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]->person);
    }

}