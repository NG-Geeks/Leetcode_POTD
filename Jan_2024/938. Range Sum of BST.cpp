Question :: 938. Range Sum of BST

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Solution::

Complexity::
Time complexity:
    O(n))
Space complexity:
    O(n)


Code::

 const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
  int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)return 0;
        int sum = 0;
        if(root->val>=low && root->val <=high){
            sum +=root->val;
        }
        sum+=rangeSumBST(root->left,low,high);
         sum+=rangeSumBST(root->right,low,high);

        return sum;
    }

};