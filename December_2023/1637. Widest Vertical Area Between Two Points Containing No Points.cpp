

1637. Widest Vertical Area Between Two Points Containing No Points

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.
 
Solution::

Approach
    Just take out the x coordinates from the points .
    sort the x coordinates and stores the max difference.
    Return the max difference.

Complexity:
Time complexity:
    O(n)
Space complexity:
    o(n) && O(1)

Code:
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution{
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>v(points.size());
        for(int i=0;i<points.size();i++){
            v[i] = points[i][0];
        }
        sort(begin(v),end(v));
        int maxi = 0;
        for(int i=0;i<points.size()-1;i++){
            maxi = max(maxi , v[i+1] - v[i]);

        }
        return maxi;
    }
};
  