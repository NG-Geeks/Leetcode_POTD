Ques::  
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
Solution::
        /**
         * Definition for a binary tree node.
         * struct TreeNode {
         *     int val;
         *     TreeNode *left;
         *     TreeNode *right;
         *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
         *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         * };
         */
class Solution
{
    pair<int, int> solve(TreeNode *root, int &cnt)
    {
        if (!root)
            return {0, 0};
        if (!root->left && !root->right)
        {
            if (root->val / 1 == root->val)
                cnt++;
            return {root->val, 1};
        }

        pair<int, int> p = solve(root->left, cnt);
        pair<int, int> q = solve(root->right, cnt);
        int sum = root->val + p.first + q.first;
        int n = 1 + p.second + q.second;
        if (sum / n == root->val)
            cnt++;
        return {sum, n};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};
