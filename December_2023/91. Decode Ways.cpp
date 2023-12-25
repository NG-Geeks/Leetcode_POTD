
91. Decode Ways
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Solution::

Complexity::

Time complexity:
    O(n)
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
    vector<int>dp;
    int solve(string &s, int i){
        if(i>=s.length())return 1; // base case if index exceed length of string then we have successfully decoded the solution return 1
        if(s[i]=='0')return 0; // if at any position we get then we cannot decode because at there is no code for starting with 0
        if(i==s.size()-1)return 1; // if we reach the last position of the string then it can be said that we have decoded the string because last character is between 1 to 9 
        if(dp[i]!=-1)return dp[i]; // dp for storing the ans solved so far

        if(s[i]=='1' or (s[i]=='2' && s[i+1]>=48 && s[i+1]<=54)) // if ith char is 1 or ith char is 2 then check if next char is between 0 to 6 then solve for next part
            return dp[i] = (solve(s,i+1) + solve(s,i+2));
        else return dp[i] = solve(s,i+1); // if ith char is not 1 or 2 it's between 3 to 9 or i+1 th char is not between 0 to 6 for eg.78
    }

    int solveMem(string &s ){
        vector<int>dp(s.size()+1);
        dp[s.size()]=1; // base case at last dp[s.size()]=1
        for(int i = s.size()-1 ; i>=0 ;i--){
            if(s[i]=='0')dp[i] = 0;
           else if(i+2<dp.size() && s[i]=='1' or (s[i]=='2' && s[i+1]>=48 && s[i+1]<=54))
             dp[i] = (dp[i+1] + dp[i+2]);
             else  dp[i] = dp[i+1];
        }
        return dp[0];
    }
public:
    int numDecodings(string s ) {
        if(s[0]=='0')return 0;
        dp.resize(s.size(),-1);
        return solveMem(s);
    }
};