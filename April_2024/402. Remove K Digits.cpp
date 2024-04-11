Question ::  402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(N)

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
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char &c:num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            if(!st.empty() or c!='0')st.push(c);
        }
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty())return "0";
        string s ="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin() , s.end());
        return s;
    }
};