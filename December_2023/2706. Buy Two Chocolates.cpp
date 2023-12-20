

2706. Buy Two Chocolates

You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.
 
Solution::
Intuition
Find out the minimum two values
Approach
Take two variable and initialize with the maxValue of int.
Iterate over the loop and Find if(value < minimum )
Then initialize that value to minimum variable.
If not then initialize the second variable with minimum of two.
Complexity
Time complexity:
    1. O(n)
    2. O(n*log(n))
Space complexity:
    O(1) , in both cases

Code:
#pragma gcc optimize("03")
auto init =[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini  = INT_MAX;
        int secondmini = INT_MAX;
        for(int &i:prices){
            if(i<mini){
                secondmini = mini;
                mini = i;
            }
            else{
                secondmini = min(secondmini , i);
            }

        }
        return (money - (secondmini + mini) >=0)?money-(secondmini + mini):money;
    }
};

2 nd Approach
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
      sort(begin(prices),end(prices));
return (prices[0]+prices[1]>=money) ?prices[0]+prices[1]:money;
    }
};
  