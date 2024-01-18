Question :: 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 
 

Solution::

Complexity::
Time complexity:
    O(N)
Space complexity:
    O(1)

Code::
#pragma gcc optimize("03")
auto init =  [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int climbStairs(int n) {
        // Recursive Solution giving TLE
        // if(n<0)return 0;
        // if(n==0)return 1;
        // return  climbStairs(n-1)+ climbStairs(n-2);

        int prev = 0;
        int curr = 1;
        int next =0;
        for(int i=1 ; i<=n;i++){
            next = curr + prev;
            prev = curr;
            curr =  next;
        }
        return next;
    }
};