Ques. 
1356. Sort Integers by The Number of 1 Bits

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
Return the array after sorting it.
Solution::
class Solution {
  static int sbc(int n){
        int cnt=0;
        while(n){
           cnt += n&1;
           n>>=1;
        }
        return cnt;
    }
   static bool cmp( int &a , int &b){
        int x = sbc(a);
        int y = sbc(b);
        if(x==y)return a<b;
        return x<y;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};