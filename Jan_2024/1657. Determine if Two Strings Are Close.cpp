Question ::   1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Solution::

Complexity
Time complexity:
    O(N*logN)
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
    bool closeStrings(string word1, string word2) {
         vector<int> mp1(26, 0), mp2(26, 0);
        for(auto i : word1) mp1[i - 'a']++;
        for(auto i : word2) mp2[i - 'a']++;
        // existence checking
        for (int i = 0; i < mp1.size(); i++) {
            if ((mp1[i] == 0 && mp2[i] != 0) || (mp1[i] != 0 && mp2[i] == 0)) {
                return false;
            }
        }
        // checking if we can swap
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1 == mp2;
    }
};