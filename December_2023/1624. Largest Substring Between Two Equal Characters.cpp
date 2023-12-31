
1624. Largest Substring Between Two Equal Characters

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.


Solution::

Complexity::

Time complexity:
    O(N)
Space complexity:
    O(N)
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
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int ans = -1;

        for(int i =0;i<s.size();i++){

            if(mp.find(s[i])!=mp.end()){
                ans = max(ans,i-mp[s[i]]-1);
            }
            else{
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};