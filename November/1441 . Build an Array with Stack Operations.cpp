Ques::  
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
Solution::
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>v;
        int k=1;//initialize the varibale k to keep number of values entered  in stack 
        int i=0;
        while(k<=target[target.size()-1]){ run the loop till value of k not equal to last value of target
            if(i<target.size() && target[i] == k){ // if the value of k is present in target then push it 
                v.push_back("Push");
                k++;
                i++;
            }
            else if(i<target.size() && target[i]>k){// if the value is note prsent then push and pop it 
                v.push_back("Push");
                v.push_back("Pop");
                k++;
            }
            else break;
        }
        return v;
    }
};