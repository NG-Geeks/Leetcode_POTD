Question :: 2385. Amount of Time for Binary Tree to Be Infected

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 
 

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
void solve(TreeNode * root ,  unordered_map<TreeNode*  , TreeNode*>&m , int start , TreeNode *&s){
        if(!root)return ;
        if(root->val == start)s = root; // store the address of start value
        m[root->left] = root; // node to parent mapping
        m[root->right] = root; // node to parent mapping
        solve(root->left , m , start , s); // dfs 
        solve(root->right , m , start , s); // dfs
    }
    int Time(TreeNode* root , TreeNode* s , unordered_map<TreeNode* , TreeNode* >&m){
        unordered_map<TreeNode*  , bool>visited; // To keep check which node is visited
        queue<TreeNode*>q; // queue for bfs traversal
        q.push(s);
        visited[s] = 1;
        int ans =0;
        while(!q.empty()){
            int size = q.size();
            bool f=0;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front(); // front node of queue
                q.pop();
                if(!visited[front->left] && front->left){ // check if not visited then continue
                    q.push(front->left);
                    visited[front->left]=1;
                    f=1;
                }
                if(!visited[front->right] && front->right){// check if not visited then continue
                    q.push(front->right);
                    visited[front->right]=1;
                    f=1;
                }
                if(!visited[m[front]] && m[front]){// check if not visited then continue
                    q.push(m[front]);
                    visited[m[front]] = 1;
                    f=1;
                }
            }
            if(f)ans++;
        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*  , TreeNode*>m;
        m[root] = NULL;
        TreeNode* s;
        solve(root , m , start , s) ;
        return Time(root , s , m);
    }
};