
1758. Minimum Changes To Make Alternating Binary String

You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

Solution::

Complexity::
Time complexity:
    O(n)
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
    int solve(string &s){
        int cnt=0;
        for(int i=0;i<s.length();i++){
             if(i&1 && s[i]=='0')cnt++;
             if(i%2==0 && s[i]=='1')cnt++;
        }
        return cnt;
    }
   int solve2(string &s){
        int cnt=0;
        for(int i=0;i<s.length();i++){
             if(i&1 && s[i]=='1')cnt++;
             if(i%2==0 && s[i]=='0')cnt++;
        }
        return cnt;
    }
public:
    int minOperations(string &s) {
        int cnt=0;
        
        return min(solve(s), solve2(s));
    }
};