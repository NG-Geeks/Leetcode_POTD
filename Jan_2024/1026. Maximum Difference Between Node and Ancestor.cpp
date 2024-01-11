Question :: 1026. Maximum Difference Between Node and Ancestor
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Solution::

Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)
Code::
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
    int solve(TreeNode * root , int mini , int maxi){
        if(!root)return 0 ;

        int diff = max(abs(root->val - mini ) , abs(root->val - maxi));
        maxi = max(maxi ,root->val);
        mini = min(mini , root->val);
        int x = solve(root->left , mini , maxi);
        int y = solve(root->right , mini , maxi);
        return max(diff , max(x ,y));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return solve(root , root->val , root->val);  

    }
};