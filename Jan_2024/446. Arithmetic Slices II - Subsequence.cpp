Question :: 446. Arithmetic Slices II - Subsequence
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

Solution::

Complexity::
Time complexity:
    O(n ^2))
Space complexity:
    O(n)


Code::

#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        size_t n = nums.size();
        if(n<=2) return 0;

        int ans = 0 ; 
        unordered_map<long long,long long> dp[n+1];
        for( int i = 1 ; i < n ; i++){
            for(int  j = 0 ; j<i ; j++){
                 int cnt = 1;
                long long diff = (long long)nums[i]-(long long)nums[j];
                if(diff<INT_MIN or diff>INT_MAX)continue;
               
                if(dp[j].count(diff)){
                   cnt = dp[j][diff];
                   dp[i][diff]+= cnt;
                   ans += cnt;
                }

                dp[i][diff] += 1 ; 
            }
        }
        return ans;
    }
};