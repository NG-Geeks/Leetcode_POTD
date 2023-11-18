Ques::   1838. Frequency of the Most Frequent Element

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
 

class Solution {  
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),end(nums));
        int s = 0; 
        int e =0;
        long long sum =0;
        int ans =1;
        while(e<nums.size()){
            sum += nums[e++];
            if(k + sum <( (long) nums[e-1] * (e - s))){
                sum -=nums[s++];
            }
            ans = max(ans , e-s);
        }
        return ans;
    }
};