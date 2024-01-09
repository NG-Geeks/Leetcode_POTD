Question :: 872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 

Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)


Code::
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

 
 const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
    void solve(TreeNode* root , vector<int>&v){
        if(!root)return ;
        if(!root->left and !root->right){
            v.push_back(root->val);
            return;
        }

        solve(root->left , v);
        solve(root->right, v);
    }
    bool solve2(TreeNode* root , vector<int>&v , int &k){
        if(!root)return  1 ; // for ans to 
        if(!root->left and !root->right){
            if(k>=v.size())return 0; // if second root contains more no. of elements leaf values then first one
            return v[k++]==(root->val); // check whether they are equal are not
        }

        return solve2(root->left , v , k) && solve2(root->right, v,k);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       if(!root1 or !root2)return 0;
       vector<int>v1; // store the leat values
       solve(root1, v1);
       int k =0;
       int l = solve2(root2 ,v1 , k ); // check for the next root
       if(k < v1.size())return 0; // check whether first root contains more leaf values then second one then return 0  
       return l;
    }
};