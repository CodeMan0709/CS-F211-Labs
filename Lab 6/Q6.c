// #include<stdio.h>

// int main()
// {
//     int n;
//     scanf("%d",&n);

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     int deque[n];
//     int front = 0;
//     int end = n-1;

//     deque[front]=arr[0];

//     for(int k=1;k<n;k++)
//     {
//         if(arr[k]>deque[front])
//         {
//             deque[end]=arr[k];
//             end--;
//         }
//         else
//         {
//             front++;
//             deque[front]=arr[k];
//         }
//     }

//     for(int i=front;i>=0;i--)
//     {
//         printf("%d ",deque[i]);
//     }

//     for(int i=n-1;i>end;i--)
//     {
//         printf("%d ",deque[i]);
//     }

// }

#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int val;
    struct linkedList *next;
    struct linkedList *prev;
};
typedef struct linkedList Node;

int main()
{
    int n;
    scanf("%d", &n);

    Node *head = NULL;

    int temp;
    Node *front;
    Node *back;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = malloc(sizeof(Node));
        scanf("%d", &temp);
        newNode->val = temp;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (i == 0)
        {
            head = newNode;
            back = head;
            front = head;
        }
        else
        {
            if (newNode->val < back->val)
            {
                back->prev = newNode;
                newNode->next = back;
                back = newNode;
            }
            else
            {
                newNode->prev = front;
                front->next = newNode;
                front = newNode;
            }
        }
    }
    while (back != NULL)
    {
        printf("%d ", back->val);
        back = back->next;
    }
}