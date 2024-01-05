Question :: 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing 
subsequence

 

Solution::

Complexity::
Time complexity:
    O(n * long)
Space complexity:
    O(n)


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
    int lengthOfLIS(std::vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>ans;
        ans.push_back(nums[0]); // first element is always sorted
        for(int i =1 ; i<nums.size();i++){
            if(nums[i]>ans.back())ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin() , ans.end() , nums[i]) - ans.begin(); // lowerbound provides the address of the 
//position whose value is just smaller then it's value or 
//equal to it's value
// which on subtacting with its first address which can be get through begin() function provides index of that number
                ans[index] = nums[i]; // assign the value to in sorted manner
            }
        }
        return ans.size();

        
    }
};