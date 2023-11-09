Ques::
1759. Count Number of Homogenous Substrings

Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 
 
#define MOD 1000000007
class Solution {
public:
    int countHomogenous(string s) {
        if(s.length() == 1)return 1;
        int i=0;
        int j=1;
        long long cnt=1;
        int ans=0;
        while(j<s.length() ){
            if(s[i]==s[j]){
               cnt++;
               j++;}
            else{
              ans +=((cnt*(cnt+1))/2)%MOD;  
              cnt=1; 
              i =j;
              j = j+1;
              }
        } 
        ans +=((cnt*(cnt+1))/2)%MOD;  
        return ans;
    }
};