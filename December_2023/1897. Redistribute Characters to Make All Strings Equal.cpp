
1897. Redistribute Characters to Make All Strings Equal

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

 


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
    bool makeEqual(vector<string>& words) {
        vector<int> counts(26, 0);
        for (string word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.size();
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};