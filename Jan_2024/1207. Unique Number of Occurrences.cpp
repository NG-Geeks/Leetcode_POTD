Question :: 1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of 
each value in the array is unique or false otherwise.

 

Solution::

Complexity::
Time complexity:
    O(N)
Space complexity:
    O(N)

Code::

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int &i:arr)m[i]++; // store count of each element
        set<int>s;
        for(auto &i:m){
           s.insert(i.second); // store unique count of element
        }
        return s.size()==m.size(); // if all have unique number occurences then return true
    }
};