Question ::  85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

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