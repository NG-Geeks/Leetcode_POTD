Question :: 2108. Find First Palindromic String in the Array

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
Solution::

Complexity
Time complexity:
O(s) , s = length of max string
Space complexity:
O(1)
Code
#pragma gcc optmize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
    bool palindrome(string s){
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i])
              return 0;
        }
        return 1;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(palindrome(words[i]))
               return words[i];
        }
        return "";
    }
};