
1903. Largest Odd Number in String
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 
Solution::
Approach ::
        Traverse from the last and see if the number is odd then we 
         got the number that is greater as 145 < 12765 and it's and odd
         number.

Complexity
Time complexity:
     O(N)
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
    string largestOddNumber(string s) {
        for(int i = s.length()-1 ; i >= 0 ; i--){
           if((s[i]-'0')&1){
               return s;}
               s.pop_back();
       }
       return "";
    }
};