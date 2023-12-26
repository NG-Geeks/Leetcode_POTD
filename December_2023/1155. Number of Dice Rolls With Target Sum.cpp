
1155. Number of Dice Rolls With Target Sum

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Solution::

Complexity::

Time complexity:
    O(n*k)
Space complexity:
    O(n)
Code
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
    const int mod = 1e9+7;
    int solveMem(int dice , int faces , int target , vector<vector<int>>&dp){
        if(target<0)return 0;
        if(dice!=0 && target==0)return 0;
        if(dice ==0 && target!=0)return 0;
        if(dice==0 && target ==0)return 1;

        if(dp[dice][target]!=-1)return dp[dice][target];
        int ans =0;
        for(int i=1;i<faces+1;i++){
            ans = (ans + solveMem(dice-1 , faces , target - i , dp))%mod;
        }
        return dp[dice][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solveMem(n,k,target , dp);
    }
};