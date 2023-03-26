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

void preOrder(TreeNode * root)
{
    if(root==NULL)
    return;

    preOrder(root->left);
    preOrder(root->right);
    cout<<root->val<<" ";
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

    while (root != NULL && root->val < l)
    {
        root = root->right;
    }

    while (root != NULL && root->val > r)
    {
        root = root->left;
    }
    // cout<<root->val;

    TreeNode *temp = root;

    while (temp->left != nullptr && temp->left->val >= l)
    {
        temp = temp->left;
    }

    while (temp != NULL && temp->left != NULL && temp->left->val < l)
    {
        TreeNode *delhelp = temp->left;
        temp->left = temp->left->right;
        delete (delhelp);
    }

    temp = root;

    while (temp->right != nullptr && temp->right->val <= r)
    {
        temp = temp->right;
    }

    while (temp->right != NULL && temp->right->val > r)
    {
        TreeNode *delhelp = temp->right;
        temp->right = temp->right->left;
        delete (delhelp);
    }

    preOrder(root);
}