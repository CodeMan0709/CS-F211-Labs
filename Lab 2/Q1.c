#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
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
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
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

// Prints the values stored in the nodes of the given singly linked list
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
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
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