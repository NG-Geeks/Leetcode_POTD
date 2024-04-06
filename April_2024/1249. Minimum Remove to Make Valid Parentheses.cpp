Question ::1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 
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
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0 ; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if( s[i] == ')'){
                if(!st.empty() && s[st.top()]=='(')
                    st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};