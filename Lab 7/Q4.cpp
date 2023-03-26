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
        if (arr[i - 1] != -1)
        {
            root = new TreeNode(arr[i - 1]);
            root->left = construct_tree(arr, 2 * i, max);
            root->right = construct_tree(arr, 2 * i + 1, max);
        }
    }
    return root;
}

void modify(TreeNode *root, int *sum)
{
    if (root == NULL)
        return;

    modify(root->right, sum);
    *sum = *sum + root->val;
    root->val = *sum;

    modify(root->left, sum);
}

void change(TreeNode *root)
{
    int sum = 0;
    modify(root, &sum);
}

// void inorder(TreeNode *root)
// {
//     if (root == NULL)
//         return;

//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

void storearr(TreeNode *head, int arr[], int j)
{
    if (head == NULL)
    {
        return;
    }
    arr[j] = head->val;
    storearr(head->left, arr, 2 * j + 1);
    storearr(head->right, arr, 2 * j + 2);
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

    TreeNode *root = construct_tree(arr, 1, n);
    change(root);
    // inorder(root);

    storearr(root,arr,0);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}