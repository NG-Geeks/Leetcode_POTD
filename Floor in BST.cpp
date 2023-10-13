Floor in BST
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.
link-->>>>    https://practice.geeksforgeeks.org/problems/floor-in-bst/1                                                                                 
 class Solution
{

public:
    int floor(Node *root, int x)
    {
        if (!root)
            return -1;
        if (root->data == x)
            return x;
        int maxi = INT_MIN;
        if (root->data <= x)
            maxi = root->data;
        if (root->left)
        {
            maxi = max(maxi, floor(root->left, x));
        }
        if (root->right)
        {
            maxi = max(maxi, floor(root->right, x));
        }
        return maxi != INT_MIN ? maxi : -1;
    }
};
