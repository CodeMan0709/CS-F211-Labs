#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

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

void postOrder(TreeNode * root)
{
    if(root==NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

TreeNode *beauty(TreeNode * root,int l,int r)
{
    if(root==NULL)
    return NULL;

    if(root->val >=l && root->val <=r)
    {
        root->left = beauty(root->left,l,r);
        root->right = beauty(root->right,l,r);
    }
    else if(root->val >=l && root->val >r)
    {
        root = beauty(root->left,l,r);
    }
    else if(root->val<l && root->val <=r)
    {
        root = beauty(root->right,l,r);
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

    TreeNode *root = convert(arr, 0, n);
    TreeNode * ans = beauty(root,l,r);
    postOrder(ans);
}