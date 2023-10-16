119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Solution::
class Solution
{
public:
    vector<int> getRow(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> r(i + 1, 1);
            for (int j = 1; j < i; j++)
            {

                r[j] = (ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans.push_back(r);
        }
        return ans[numRows];
    }
};