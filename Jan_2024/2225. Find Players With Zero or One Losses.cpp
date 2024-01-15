Question ::   2225. Find Players With Zero or One Losses

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Solution::
Approach
    1. Make set to all element of matches uniquely.
    2. make an map to store count of losers i.e. how mant times 
       they have lost.
    3. The element which are not in map are winner so store in 
       answer vector.
    4. THe element which have count 1 store in it vector and 
       store in ans vector.
Complexity
Time complexity:
    O(N)
Space complexity:
    O(N)
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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>s;
        unordered_map<int , int>v;
        vector<vector<int>>ans(2);
        for(auto&j:matches){
                s.insert(j[0]);
                s.insert(j[1]);
                 v[j[1]]++;
            
        }
        vector<int>res;
        for(auto &i:s){
            if(v.find(i)==  v.end()){
                 res.push_back(i);
            }
        }
        sort(begin(res) , end(res));
        ans[0] = res;
        res.clear();
        for(auto &i:v){
            if(i.second ==1)res.push_back(i.first);
        }
        sort(begin(res) , end(res));
        ans[1] = res;
        return ans;
    }
};