#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode():val(0),left(NULL),right(NULL) {};
    TreeNode(int x):val(x),left(NULL),right(NULL) {};
    TreeNode(int x,TreeNode * left , TreeNode * right):val(x),left(left),right(right) {};
};

void postOrder(TreeNode * root,int l,int r)
{
    if(root==NULL)
    return;

    postOrder(root->left,l,r);
    postOrder(root->right,l,r);

    if(root->val >=l && root->val <=r)
    cout<<root->val<<" ";
}

TreeNode * makeTree(int arr[],int s,int e)
{
    TreeNode * root = NULL;

    if(arr[s] != -1 && s<e)
    {
        root = new TreeNode(arr[s]);
        root->left= makeTree(arr,2*s+1,e);
        root->right= makeTree(arr,2*s+2,e);
    }

    return root;
}

int main()
{
    int n, l, r;

    cin >> n >> l >> r;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    TreeNode * root = makeTree(arr,0,n);
    postOrder(root,l,r);
}