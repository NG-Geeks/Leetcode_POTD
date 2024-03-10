Question :: 349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 
Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(N)

 Code::
#pragma gcc optmize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>m;
        for(int i=0; i<nums2.size(); i++){
            m.insert(nums2[i]);
        }
        for(int &k:nums1){
            if(m.find(k)!=m.end())
              ans.push_back(k);
        }
        m.clear();
        for(int &k:ans){
            m.insert(k);
        }
        ans.clear();
        for(auto &k:m){
            ans.push_back(k);
        }
        return ans;
    }
};