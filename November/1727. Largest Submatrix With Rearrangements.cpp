
1727. Largest Submatrix With Rearrangements

You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.


Solution:: 
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
              int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int r =0;r<m;r++){
            for(int c=0 ; c<n;c++){
                if(matrix[r][c]!=0 and r>0){
                    matrix[r][c] +=matrix[r-1][c];
                }
            }
        

        vector<int>currRow = matrix[r];
        sort(currRow.begin() , currRow.end() ,greater());
        for(int i=0;i<n;i++){
            ans = max(ans , currRow[i] * (i+1));
        }
        }

        // vector<pair<int,int>>prevheight;

        // for(int row =0; row<m;row++){
        //     vector<pair<int,int>>heights;
        //     vector<bool>seen(n,0);
        //     for(auto [height , col] : prevheight){
        //         if(matrix[row][col] == 1){
        //             heights.push_back({height+1 , col});
        //             seen[col] = 1;
        //         }
        //     }
        //     for(int col =0 ; col<n;col++){
        //         if(seen[col] == false && matrix[row][col] ==1){
        //             heights.push_back({1,col});
        //         }
        //     }
        //     for(int i=0;i<heights.size();i++){
        //         ans = max(ans , heights[i].first*(i+1));
        //     }
        //     prevheight = heights;
        // }
        return ans;
    }
};