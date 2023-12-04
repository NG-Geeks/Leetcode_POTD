
2264. Largest 3-Same-Digit Number in String

You are given a string num representing a large integer. An integer is good if it meets the following conditions:
It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.
Note:
A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.

Solution::

#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    string largestGoodInteger(string num) {
        string s;
        for(int i=0;i<num.length();i++){
            if(num[i] == num[i+1]){
                 if( i+2<num.size() && num[i+1]==num[i+2])
                    if(s.empty() || (s[0]-'0') <(num[i] -'0')){
                      s = string(3,num[i]);
                      i+=2;
            }
            }
        }
        return s;
    }
};


2nd. Approach 

class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt=1;
        string x="";
        string s="";
        for(int i=0;i<num.size()-1;i++){
            if(num[i]==num[i+1]){
                cnt++;
                if(cnt==3){
                    s+=num[i];
                    s+=num[i];
                    s+=num[i];
                    if(x.size()==0){
                        x=s;
                    }
                    else if(x[0]<s[0]){
                        x=s;
                    }
                }
                s="";
            }
            else{
                cnt=1;
            }
        }
        return x;
    }
};