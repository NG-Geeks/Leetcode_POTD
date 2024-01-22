Question :: 645. Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
Solution::

Complexity::
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
    vector<int> findErrorNums(vector<int>& nums) {
   int duplicate;

    for (const int num : nums)
      if (nums[abs(num) - 1] < 0)
        duplicate = abs(num);
      else
        nums[abs(num) - 1] *= -1;
    
    for(int i : nums)cout<<i<<" ";
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > 0)
        return {duplicate, i + 1};
        throw;
    }
};