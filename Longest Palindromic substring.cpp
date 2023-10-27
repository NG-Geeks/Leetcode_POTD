
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring.


class Solution
{
public:
    string longestPalindrome(string &s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxi = 0;
        string ans;
        for (int diff = 0; diff < n; diff++)
        {
            for (int i = 0, j = diff; j < n; j++, i++)
            {
                if (diff == 0)
                {
                    dp[i][j] = 1;
                }
                else if (diff == 1)
                {
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                }
                else if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                if (dp[i][j] && maxi < diff + 1)
                {
                    maxi = diff + 1;
                    ans = s.substr(i, maxi);
                }
            }
        }

        return ans;
    }
};