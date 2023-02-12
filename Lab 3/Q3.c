#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool findPair(Node * head,int sum)
{
    Node * right =head;
    while(right->next != NULL)
    {
        right=right->next;
    }
    Node * left = head;
    
    bool ans = 0;

    while(left != right && right->next != left)
    {
        if(left->data + right->data==sum)
        {
        ans=1;
        printf("%d %d \n",left->data,right->data);
        return ans;
        }

        else if(left->data + right->data<sum)
        {
            left=left->next;
        }

        else
        {
            right=right->prev;
        }
    }

    return ans;

}

int main()
{
    int k;
    scanf("%d",&k);
    Node * head = readList();

    bool ans = findPair(head,k);
    printf("%d",ans);
}