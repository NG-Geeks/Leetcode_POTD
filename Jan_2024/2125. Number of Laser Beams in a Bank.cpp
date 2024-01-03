Question :: 2125. Number of Laser Beams in a Bank

Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.


Solution::


Approach
    Just count the number of ones in the first string 
     and multiply with count of ones in second string 
     if found otherwise multiply with next row if found.

     
Time complexity:
$$O(n^2)$$
Space complexity:
$$O(1)$$


Code::
#pragma gcc optimize("03")
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
    int check(string &s){
        int cnt =0;
        for(auto &i:s){
            if(i=='1')cnt++;
        }
        return cnt;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =0 ; // to store the ans
        int cnt=check(bank[0]) ;
        for(int i = 1 ;i<bank.size() ; i++){
            string s  = bank[i]; // assign the string to variable s
            int one = check(s); // store the number of ones in the string
            if(one ==0 )continue; // if count of ones is zero then move to next row
            ans += ( cnt* one); // multiply previous count of ones with current count
            cnt = one; //update the cnt to current number of ones.
             
        }
        return ans;
    }
};