867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.


Solution::
Approach
    For the matrix create the matrix of same size and then 
    assing 
    matrix2[j][i] = matrix[i][j]
    so that value is assigned properly.
Complexity
Time complexity:
    O(n^2)
Space complexity:
    O(n^2)
Code
#pragma gcc optimize("03")
auto init =[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix[0].size(), vector<int>(matrix.size()));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                v[j][i]=matrix[i][j];
            }
        }
        return v;

    }
};
You can visit on github page for the leetcode soluions of the other problem

https://github.com/Nilesh-geeks/Leetcode_Sol