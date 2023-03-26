#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *construct_tree(int *arr, int i, int max)
{
    TreeNode *root = nullptr;
    if (i <= max)
    {
        if (arr[i-1] != -1)
        {
            root = new TreeNode(arr[i-1]);
            root->left = construct_tree(arr, 2 * i , max);
            root->right = construct_tree(arr, 2 * i + 1, max);
        }
    }
    return root;
}

int pathSum(TreeNode * root,int x)
{
    if(root==NULL)
    return 0;

    int count = 0;

    x = x - root->val;

    if(x==0 && root->left==NULL && root->right==NULL)
    {
        count++;
    }

    if(root->left)
    count = count + pathSum(root->left,x);
    if(root->right)
    count = count + pathSum(root->right,x);

    return count;

}

// void inorder(TreeNode * root)
// {
//     if(root == NULL)
//     return ;

//     inorder(root->right);
//     inorder(root->left);
//     cout<<root->val<<" ";
    
// }

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    TreeNode * root = construct_tree(arr,1,n);

    // inorder(root);
    // cout<<endl;

    int ans = pathSum(root,x);
    cout<<ans;
    return 0;
}