Question ::   1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Solution::

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
    int minSteps(string s, string t) {
        int mp[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            mp[t[i] - 'a']++;
            mp[s[i] - 'a']--;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += max(0, mp[i]);
        }
        
        return ans;
    }
};