Question ::100. Same Tree

Given the roots of two binary trees p and q,write a function to check if they are the same or not .

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(1)

 Code::
#pragma gcc optimize("03")
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL and q == NULL)
            return 1;
        if (p == NULL || q == NULL)
            return 0;
        if (p->val != q->val)
            return 0;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};