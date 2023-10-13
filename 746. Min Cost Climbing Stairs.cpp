You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
link->>https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution
{
    vector<int> dp;
    int solve(vector<int> &nums, int i)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = nums[i];
        ans += solve(nums, i + 1);
        int ans1 = nums[i];
        ans1 += solve(nums, i + 2);
        return dp[i] = min(ans, ans1);
    }
    int solve3(vector<int> &nums)
    {
        int n = nums.size();
        int prev2 = nums[0];
        int prev1 = nums[1];
        for (int i = 2; i < n; i++)
        {
            int curr = nums[i] + min(prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // dp.resize(cost.size()+1,-1);
        // return min(solve(cost , 0) , solve(cost , 1));
        return solve3(cost);
    }
};