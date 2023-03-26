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

TreeNode *convert_to_tree(int *arr, int index, int max)
{
    TreeNode *root = nullptr;
    if (index < max && arr[index] != -1)
    {
        root = new TreeNode(arr[index]);
        root->left = convert_to_tree(arr, 2 * index + 1, max);
        root->right = convert_to_tree(arr, 2 * index + 2, max);
    }
    return root;
}

void large(TreeNode * root,int *k,bool *check)
{
    if(root == NULL || *check)
    return ;

    large(root->right,k,check);

    if(--(*k)==0)
    {
        cout<<root->val;
        *check=1;
        return ;
    }
    else
    {
        large(root->left,k,check);
    }
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    TreeNode *root = convert_to_tree(arr, 0, n);
    
    bool check =0;  
    large(root,&k,&check);
    
}

