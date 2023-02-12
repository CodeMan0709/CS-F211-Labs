#include <stdio.h>
#include <stdlib.h>

int k;
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
    scanf("%d",&k);
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

Node * rotate(Node * head,int k)
{
    if(k==0)
    return head;

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    } 
    
    Node * last = temp;
    last->next=head;
    head->prev=last;
    

    int count=1;
    while(count<k)
    {
        temp = temp->prev;
        count++;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;

    return temp;
    
}

int main()
{
    Node * head = readList();
    Node * newHead = rotate(head,k);
    printList(newHead);
    return 0;
}