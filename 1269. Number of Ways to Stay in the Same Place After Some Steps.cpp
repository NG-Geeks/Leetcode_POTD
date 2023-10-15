1269. Number of Ways to Stay in the Same Place After Some Steps

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

Solution::

class Solution
{
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(int step, int len, int index)
    {
        if (step == 0)
        {
            return index == 0 ? 1 : 0;
        }
        if (dp[step][index] != -1)
            return dp[step][index];

        int ans = (solve(step - 1, len, index)) % mod; // stay

        if (index < len - 1)
            ans = (ans + solve(step - 1, len, index + 1)) % mod;
        if (index > 0)
            ans = (ans + solve(step - 1, len, index - 1)) % mod;

        return dp[step][index] = ans;
    }
    int solveTab(int steps, int n)
    {
        dp.assign(steps + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int step = 1; step <= steps; step++)
        {
            for (int index = n - 1; index >= 0; index--)
            {
                long long ans = dp[step - 1][index];
                if (index > 0)
                {
                    ans = (ans + dp[step - 1][index - 1]) % mod;
                }
                if (index < n - 1)
                {
                    ans = (ans + dp[step - 1][index + 1]) % mod;
                }
                dp[step][index] = ans;
            }
        }
        return dp[steps][0];
    }
    int solveSp(int steps, int n)
    {
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        prev[0] = 1;
        for (int step = 1; step <= steps; step++)
        {
            for (int index = n - 1; index >= 0; index--)
            {
                long long ans = prev[index];
                if (index > 0)
                {
                    ans = (ans + prev[index - 1]) % mod;
                }
                if (index < n - 1)
                {
                    ans = (ans + prev[index + 1]) % mod;
                }
                curr[index] = ans;
            }
            prev = curr;
        }
        return curr[0];
    }

public:
    int numWays(int steps, int len)
    {
        int n = min(steps / 2 + 1, len);
        // dp.assign(steps+1 , vector<int>(n+1 , -1));
        // return solve(steps , n ,0);
        return solveSp(steps, n);
    }
};