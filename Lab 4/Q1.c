#include <stdio.h>
#include <stdlib.h>

typedef struct hehe
{
    int s;
    int e;
} gym;

void merge(gym *arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int l1 = mid - start + 1;
    int l2 = end - mid;

    gym *left[l1];
    gym *right[l2];

    int k = start;
    for (int i = 0; i < l1; i++)
    {
        left[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        right[i] = arr[k++];
    }
    int i1 = 0;
    int i2 = 0;
    k = start;
    while (i1 < l1 && i2 < l2)
    {
        if (left[i1]->s < right[i2]->s)
        {
            arr[k++] = left[i1++];
        }
        else if (left[i1]->s == right[i2]->s)
        {
            if (left[i1]->e < right[i2]->e)
            {
                arr[k++] = left[i1++];
                arr[k++] = right[i2++];
            }
            else
            {
                arr[k++] = right[i2++];
                arr[k++] = left[i1++];
            }
        }
        else
        {
            arr[k++] = right[i2++];
        }
    }
    while (i1 < l1)
    {
        arr[k++] = left[i1++];
    }
    while (i2 < l2)
    {
        arr[k++] = right[i2++];
    }
}

void mergeSort(gym * arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

// void slotbook(gym *arr[], int n)
// {
//     int snew;
//     int enew = 0;
//     int count = 0;
//     // int ans[2 * n];
//     // int a = 0;
//     for (int i = 0; i < n; i++)
//     {

//         if (arr[i]->e >= arr[i + 1]->s)
//         {
//             snew = arr[i]->s;
//             int j = i + 1;
//             while (arr[j]->e >= arr[j + 1]->s && j<n)
//             {
//                 enew = arr[j]->e;
//                 enew = max(enew, arr[j + 1]->e);
//                 j++;
//             }
//             count++;
//             i = i + j;
//             printf("%d %d", snew, enew);
//             printf("\n");
//         }
//         else
//         {
//             count++;
//             snew = arr[i]->s;
//             enew = arr[i]->e;
//             printf("%d %d\n", snew, enew);
//         }

//         // enew=0;
//         // else
//         // {
//         //     count++;
//         // }
//     }
//     printf("%d", count);
// }

void newSlot(gym *arr[],int n)
{
    int count=0;
    gym *new[n];
    new[0]=arr[0];

    for(int i=0;i<n;i++)
    {
        gym * temp;
        temp = malloc(sizeof(gym));
        new[i]=temp;
    }

    for(int i=1;i<n;i++)
    {
        if(arr[i]->s <= new[count]->e)
        {
            if(arr[i]->e > new[count]->e)
            new[count]->e=arr[i]->e;
            // count++;
        }
        else
        {
            count++;
            new[count]=arr[i];
        }
    }
    printf("%d\n",count+1);
    for(int i=0;i<=count;i++)
    {
        printf("%d %d \n",new[i]->s,new[i]->e);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    gym * arr[n];

    for(int i=0;i<n;i++)
    {
        gym * temp;
        temp = malloc(sizeof(gym));
        arr[i]=temp;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i]->s, &arr[i]->e);
    }

    mergeSort(arr, 0, n - 1);
    for(int i=0;i<n;i++)
    {
        printf("%d %d \n",arr[i]->s,arr[i]->e);
    }
    newSlot(arr, n);
}