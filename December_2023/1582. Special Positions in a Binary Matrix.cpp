
1582. Special Positions in a Binary Matrix

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Solution::
Complexity
Time complexity:
    O(n^2) 
Space complexity:
    O(1)

#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int rows = mat.size(), col = mat[0].size();
        int rsum[rows];
        int csum[col];
        int i, j;
        //get sum of rows
        for (i = 0; i < rows; i++)
        {
            rsum[i] = 0;
            for (j = 0; j < col; j++)
                rsum[i] += mat[i][j];
        }
        //get sum of coloumns
        for (i = 0; i < col; i++)
        {
            csum[i] = 0;
            for (j = 0; j < rows; j++)
                csum[i] += mat[j][i];
        }
        //If value in mat is one with sum of that row and col =1 then add this to result
        int count = 0;
        for (i = 0; i < rows; i++)
            for (j = 0; j < col; j++)
                if (mat[i][j] == 1 && rsum[i] == 1 && csum[j] == 1)
                    count++;
        return count;
    }
};
  