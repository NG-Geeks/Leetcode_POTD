
link->>https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int n = nums.size();
        set<int> unique(nums.begin(), nums.end());
        nums.clear();
        int ans = n;
        for (int num : unique)
        {
            nums.push_back(num);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int left = nums[i];
            int right = left + n - 1;
            int j = upper_bound(nums.begin(), nums.end(), right) - nums.begin();
            int count = j - i;
            ans = min(ans, n - count);
        }
        return ans;
    }
};