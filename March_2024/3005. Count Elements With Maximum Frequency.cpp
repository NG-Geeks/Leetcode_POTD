Question :: 3005. Count Elements With Maximum Frequency

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.
 
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
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int &i:nums){
            m[i]++;
        }
        int maxi = 0;
        for(auto &k:m){
            if(k.second>maxi){
                maxi = k.second;
            }
        }
        cout<<maxi;
        int cnt =0;
        for( auto &i:m){
            if(i.second == maxi)cnt+=i.second;
        }
        return cnt;
    }
};