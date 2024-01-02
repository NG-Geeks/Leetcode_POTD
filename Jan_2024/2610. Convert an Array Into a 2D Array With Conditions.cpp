Question :: 2610. Convert an Array Into a 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

Solution::

Complexity::
Time complexity:
    O(N )
Space complexity:
    O(N )
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n =0;
        unordered_map<int,int>m;
        for(auto &i: nums){
            m[i]++;
            n = max(n,m[i]);
            
}
       vector<vector<int>> ans(n);
        for(auto &x: m){
           int i=0;
           int k= x.second;
           while(k--){
               ans[i].push_back(x.first);
               i++;
           }
        }
        
      
        return ans;
    }
};