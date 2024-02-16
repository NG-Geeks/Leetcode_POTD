Question :: 1481. Least Number of Unique Integers after K Removals

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 
Solution::

Complexity::

Time complexity:
O(N) 

Space complexity:
O(N)

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
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
      unordered_map<int , int>m;
      for(int i = 0 ;  i < nums.size() ; i++){
          m[nums[i]]++;
      }   
      priority_queue<int, vector<int> , greater<int>>pq;
     for (auto &i:m){
         pq.push(i.second);
     }
      while(!pq.empty() && k>0){
          int s = pq.top();
          int x =k;
          k = k-s;
         
          pq.pop();
        if(k<0)pq.push(s-x);
      }

      return pq.size();  
    }
};