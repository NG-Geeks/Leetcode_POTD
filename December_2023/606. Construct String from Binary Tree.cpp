
606. Construct String from Binary Tree
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
Solution::

Approach
This problem can be easily solved using the recursive function.
just add the root val to string by converting  it to string.
if the left part then add the parenthesis and call recursive    
function and same for the right part . 

Complexity
Time complexity:
    O(n) 
Space complexity:
    O(n)

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
class Solution {
public:
    string tree2str(TreeNode* root) {
    string ans = to_string(root->val);
		if (root->left)
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { 
			if (!root->left) ans += "()"; 
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
    }
};