Question ::  623. Add One Row to Tree

Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
Solution::

Approach::
    1. Traverse to depth -1 height .
    2. Create new Node with given val
    3. Add the left part to the left of new node and right part to the right of new node
 
Complexity::
Time complexity:
    O(N)
Space complexity:
    O(N)
Code::
class Solution {
    void solve(TreeNode* root  , int &val , int depth , int currdepth){
        if(!root)return ;
        if(currdepth == depth){
                TreeNode * left = root->left; 
                 TreeNode* newleft = new TreeNode(val);
                 root->left = newleft;
                 newleft->left = left;
            
                 TreeNode* right = root->right;
                 TreeNode* newright = new TreeNode(val);
                 root->right = newright;
                 newright->right = right;
            
        }
        
        solve(root->left , val , depth , currdepth+1);
        solve(root->right , val , depth , currdepth+1);

    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root  , val   , depth-1 , 1);
        return root;
    }
};