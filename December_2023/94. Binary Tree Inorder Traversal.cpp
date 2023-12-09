
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Solution::
Approach
 Simply do the inorder Traversal 
 first call recursively the function for the left part 
 insert the root ->val 
 call the function again recursively for the right right part.
 return the ans
Complexity
Time complexity:
    O(n)
Space complexity:
    O(n) , for storing the ans and stack memory of recurison.
Code
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
 #pragma gcc optmize("03")
 auto init = [](){
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     return 0;

 }();
class Solution {
     vector<int>v;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return v;
    }
};