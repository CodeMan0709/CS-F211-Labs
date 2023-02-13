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
    if(n==1)
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
    int check=0;
    while (curright->next != NULL)
    {
        curright = curright->next;
    }
    int left = 1, right = 1;
    int lsum = curleft->data;
    int rsum = curright->data;

    while (curleft != curright)
    {

        if (lsum == rsum)
        {
            while(curleft->next->data == curright->prev->data && curleft->next != curright && curright->prev != curleft)
            {
                curleft=curleft->next;
                curright=curright->prev;
                left++;
                right++;
            }
            printf("%d %d", left, right);
            check=1;
            break;
        }
        else if(lsum<rsum)
        {
            curleft=curleft->next;
            lsum = lsum + curleft->data;
            left++;
        }
        else
        {
            curright = curright->prev;
            rsum = rsum +curright->data;
            right++;
        }
    }
    if(check==0)
    printf("NOT POSSIBLE");
}

int main()
{
    Node *head = readList();
    twoTeam(head);
    return 0;
}