661. Image Smoother

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

 
Solution::
Approach
 Just iterate through the following vectors
  Add the all neighbour of the particular element along with it 
    and take the average.
  And store the reuslt in result.
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
    int solve(int i , int j,vector<vector<int>>&mat){
        int ans = mat[i][j];
        int cnt=1;
        if(i-1>=0 ){
            ans += mat[i-1][j];
            cnt++;
        }
        if(i+1<mat.size()){
            ans += mat[i+1][j];
            cnt++;
        }
        if(j-1>=0){
            ans +=mat[i][j-1];
            cnt++;
        }
        if(j+1<mat[0].size()){
            ans +=mat[i][j+1];
            cnt++;
        }
        if(i-1>=0 &&j-1>=0){
            ans+=mat[i-1][j-1];
            cnt++;
        }
        if(i-1>=0 && j+1<mat[0].size()){
            ans+=mat[i-1][j+1];
            cnt++;
        }
        if(i+1<mat.size() && j+1<mat[0].size()){
            ans+=mat[i+1][j+1];
            cnt++;
        }
        if(i+1<mat.size() && j-1>=0){
            ans += mat[i+1][j-1];
            cnt++;
        }
        return ans/cnt;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>v(img.size() , vector<int>(img[0].size()));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                v[i][j] = solve(i,j,img);
            }
        }
        return v;
    }
};
  