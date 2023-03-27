#include <iostream>
// #include <bits/stdc++.h>
#include<map>
#include<math.h>
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

// int findPos(int in[],int element,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(in[i]==element)
//         return i;
//     }
//     return -1;
// }

int tree_height(TreeNode *root)
{
    if (!root)
        return 0;
    else
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
// void createMap(int in[], map<int, int> &nodeToIndex, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         nodeToIndex[in[i]] = i;
//     }
// }

TreeNode *generateTree(int in[], int pre[], int &index, int ins, int ine, int size, map<int, int> &nodeToIndex)
{
    if (index >= size || ins > ine)
    {
        return NULL;
    }

    int element = pre[index++];
    TreeNode *temp = new TreeNode(element);
    // int pos = findPos(in,element,size);
    int pos = nodeToIndex[element];

    temp->left = generateTree(in, pre, index, ins, pos - 1, size, nodeToIndex);
    temp->right = generateTree(in, pre, index, pos + 1, ine, size, nodeToIndex);

    return temp;
}

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

    int pre[n];
    int in[n];

    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }


    map<int, int> nodeToIndex;

    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }

    // createMap(in, nodeToIndex, n);

    int preIndex = 0;
    TreeNode *a = generateTree(in, pre, preIndex, 0, n - 1, n, nodeToIndex);
    int h = tree_height(a);

    int arrele = pow(2,h) - 1;
    // cout<<arrele<<" ";
    int ans[arrele];

    for(int i=0;i<arrele;i++)
    {
        ans[i]=-1;
    }
    storearr(a,ans,0);

    
    for(int i=0;i<arrele;i++)
    {
       cout<<ans[i]<<" ";
    }

    return 0;
}