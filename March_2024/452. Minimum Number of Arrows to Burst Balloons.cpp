Question :: 
452. Minimum Number of Arrows to Burst Balloons
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons. 

Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(1)

 Code::

#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , end(points));
        int cnt = 1 ;
        int last = points[0][1];
        for(int i =0 ; i<points.size() ; i++){
            if(points[i][0]> last){
                cnt++;
                last = points[i][1];
            }
            last = min(points[i][1] , last);
       }
       return cnt;
    }
};