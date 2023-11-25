
1685. Sum of Absolute Differences in a Sorted Array

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

#pragma gcc optimize("03")
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>v(nums.size());
       
        int leftsum =0;
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            int r = totalsum - leftsum - nums[i];

            int leftcount = i;
            int rightcount = nums.size()-1-i;

            int lefttotal = leftcount * nums[i] - leftsum;
            int righttotal = r - rightcount* nums[i];
            leftsum+=nums[i];
            v[i] = lefttotal + righttotal;
        }
        return v;
    }
};

auto init = [](){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 'c';
}();