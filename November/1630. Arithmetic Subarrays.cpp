1630. Arithmetic Subarrays
A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:

1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
#pragma GCC optimize("03")
class Solution {
    bool check(vector<int>nums , int l  , int r){
        sort(nums.begin()+l , nums.begin()+r+1);
        if(l==r or l+1 ==r )return 1; 
        int k = nums[l+1] - nums[l];
        for(int i= l+1;i<r;i++){
            if(nums[i+1] -nums[i] !=k )return 0;
        }
        return 1;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // sort(nums.begin(),nums.end());
        vector<bool>v(l.size() , 0);
        for(int i= 0 ; i<l.size() ; i++){
            if(check(nums ,l[i] , r[i]))v[i] = 1;
        }
        return v;
    }
}; 
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();