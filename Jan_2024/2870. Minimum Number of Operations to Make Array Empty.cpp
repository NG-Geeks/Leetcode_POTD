Question :: 2870. Minimum Number of Operations to Make Array Empty

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.


Solution::

Approach
  1. Store the count of the element.
  2. Follow the condition and check whether it is divisible or not.
  3. update the count variable accordingly.

Complexity::
Time complexity:
    $$O(n)$$
Space complexity:
    $$O(n)$$

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
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int&i:nums){
            m[i]++; // store the count of element.
        }
        int cnt=0;
        for(auto &i:m){
           if(m[i.first]%3==0)
            {
                cnt+=m[i.first]/3; // if  count of element is divisible by 3 then add how many multiple of 3 is there.
            }
            else if(m[i.first]>3 && (m[i.first]%3<=2)){
               cnt+=m[i.first]/3+1; // if the count of element is divisble by 3 count quotient +1 because let 4 be count of any element then 4/3 =1 and so it count will be increased by 1+1(quotient + 1) and if 4/2 = 2 it is same as 4/3 will alo provide 2
            }
           else if(m[i.first]%2==0){
               cnt+=m[i.first]/2; if cnt is less then 3 of any element 
           }
          
            else{
                return -1; // if count is 1  of an element then return -1
            }
            
        }
        return cnt;
    }
};