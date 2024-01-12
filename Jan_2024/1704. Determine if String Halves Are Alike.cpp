Question ::   1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.
Solution::

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
    bool halvesAreAlike(string s) {
    
         int cnt=0;
         for(int i=0;i<s.length()/2;i++){
             if(s[i]=='a' || s[i] == 'e' || s[i]=='i' || s[i]=='o' || s[i]=='u'||
             s[i]=='A' || s[i] == 'E' || s[i]=='I' || s[i]=='O' || s[i]=='U')cnt++;
         }
           for(int i=s.length()/2;i<s.length();i++){
              if(s[i]=='a' || s[i] == 'e' || s[i]=='i' || s[i]=='o' || s[i]=='u'||
              s[i]=='A' || s[i] == 'E' || s[i]=='I' || s[i]=='O' || s[i]=='U')cnt--;
         }
         return cnt==0;
    }
};