
1578. Minimum Time to Make Rope Colorful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.


Solution::

Complexity::

Time complexity:
    O(N)
Space complexity:
    O(1)
Code
#pragma gcc optimize("03")
auto init = [] (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int minCost(string colors, vector<int>& n) {
        int cnt=0;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]== colors[i+1]){
             
                    cnt+=min(n[i] , n[i+1]); // count the minimum value
                    n[i+1]  = max(n[i],n[i+1]); // assign the max value to i+1th  
                

            }
        }
        return cnt;
    }
};