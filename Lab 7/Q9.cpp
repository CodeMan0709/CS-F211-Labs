#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

TreeNode *convert(int arr[], int i, int n)
{
    TreeNode *root = nullptr;

    if (i < n && arr[i] != -1)
    {
        root = new TreeNode(arr[i]);
        root->left = convert(arr, 2 * i + 1, n);
        root->right = convert(arr, 2 * i + 2, n);
    }
    return root;
}

TreeNode * ancestor(TreeNode * root, int a,int b)
{
    if(root == NULL)
    return NULL;

    if(root->val == a || root->val == b)
    return root;

    TreeNode * leftsearch = ancestor(root->left,a,b);
    TreeNode * rightsearch = ancestor(root->right,a,b);

    if(leftsearch!=NULL && rightsearch!=NULL)
    return root;

    if(leftsearch==NULL)
    return rightsearch;

    if(rightsearch==NULL)
    return leftsearch;

}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    TreeNode * root = convert(arr,0,n);
    TreeNode * ans = ancestor(root,a,b);
    cout<<ans->val;
}