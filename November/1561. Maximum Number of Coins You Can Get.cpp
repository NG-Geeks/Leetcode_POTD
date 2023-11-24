
1561. Maximum Number of Coins You Can Get
There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

In each step, you will choose any 3 piles of coins (not necessarily consecutive).
Of your choice, Alice will pick the pile with the maximum number of coins.
You will pick the next pile with the maximum number of coins.
Your friend Bob will pick the last pile.
Repeat until there are no more piles of coins.
Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins that you can have.
#pragma GCC optimize("03")
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles) , end(piles));
        int i=0 , j=piles.size()-2;
        int cnt=0;
        while(i<j){
            cnt+=piles[j];
            j-=2;
            i+=1;
        }
        return cnt;
    }
};auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();