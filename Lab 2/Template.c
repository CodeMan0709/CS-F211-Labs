#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *addtoList(Node *head, int val)
{
    Node *temp = createNode(val);
    if (head == NULL)
        return temp;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;

    return temp;
}

Node* readList()
{
    int n;
    Node * head = NULL;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
            head = addtoList(head, x);
        else
            addtoList(head, x);
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeList(Node *head)
{
    Node *cur, *nxt;
    cur=head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
int findMedian(Node *head)
{
    int length = 0;
    int median = -99;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp=temp->next;
    }
    
    temp = head;
    int odd = 1;
    int even = 1;
    if (length % 2 == 1)
    {
        while (odd < (length / 2) + 1)
        {
            temp = temp->next;
            odd++;
        }
        median = temp->data;
    }
    temp = head;
    if (length % 2 == 0)
    {
        while (even < length / 2)
        {
            temp = temp->next;
            even++;
        }
        median = (temp->data + temp->next->data) / 2;
    }

    return median;
}

int main()
{
    Node *head = readList();
    int median = findMedian(head);
    printf("%d\n", median);
    freeList(head);

    return 0;
}