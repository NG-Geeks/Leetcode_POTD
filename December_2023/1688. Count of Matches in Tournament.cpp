
1688. Count of Matches in Tournament

You are given an integer n, the number of teams in a tournament that has strange rules:

If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
Return the number of matches played in the tournament until a winner is decided.

 
Solution::
Approach ::
    If you observe the number of teams then you realize for winner 
    if there are n teams then there will be n-1 matches for a team 
    to be declared as winner.

Complexity
Time complexity:
     O(1)
Space complexity:
     O(1)

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
    int numberOfMatches(int n) {
        // Approach 1
         int cnt=0;
         while(n!=1){
            if(n&1){
                cnt+=(n-1)>>1 ; // dividing n/2 and add it to ans
               cout<<n<<" ";
                n = ((n-1)>>1)+1 ; // dividing n/2 and adding 1 to it.
            }
            else{
               cnt+=(n>>1); // dividing n/2 and add it to ans
               n = n>>1;  // dividing n/2 
            }
        }
         return cnt;

        // Approach 2
        return  n-1;
    }
};