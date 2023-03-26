#include <stdio.h>
#include <stdlib.h>

typedef struct hehe
{
    long long int data;
    struct hehe *next;
    struct hehe *prev;
} Node;

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return newNode;
}

Node *readList()
{
    long long int n;
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("2 Teams not possible");
        return NULL;
    }
    Node *head = NULL;
    for (long long int i = 0; i < n; ++i)
    {
        long long int x;
        scanf("%lld", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void twoTeam(Node *head)
{
    Node *temp = head;
    Node *curleft = head;
    Node *curright = head;
    int check = 0;

    while (curright->next != NULL)
    {
        curright = curright->next;
    }
    
    int left = 1, right = 1;
    int lsum = curleft->data;
    int rsum = curright->data;
    int lfinal=0,rfinal=0;

    while (curleft != curright)
    {
        if (lsum < rsum)
        {
            curleft = curleft->next;
            lsum = lsum + curleft->data;
            left++;
        }
        else if(lsum > rsum)
        {
            curright = curright->prev;
            rsum = rsum + curright->data;
            right++;
        }
        else if(lsum == rsum)
        {
            lfinal=left;
            rfinal=right;
            curleft = curleft->next;
            lsum = lsum + curleft->data;
            left++;
            // curright = curright->prev;
            // rsum = rsum + curright->data;
            // right++;
        }
    }
    printf("%d %d", lfinal, rfinal);
}

int main()
{
    Node *head = readList();
    twoTeam(head);
    return 0;
}