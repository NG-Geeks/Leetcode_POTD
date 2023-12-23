
1496. Path Crossing

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
 

Solution::
Approach
  Take set and insert the starting points and take two variable 
   which follows one direction in positive value and opposite 
    in negative value then insert in set every position 
 2. While inserting check whether the position is already present or not if present then return true .


Complexity::
Time complexity:
    O(n)
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
    bool isPathCrossing(string path) {
        unordered_set<string>seen = {"0,0"};
        int x =0;
        int y=0;
      for(char &d:path){
        if(d=='N')y++;
        else if(d=='E')x++;
        else if(d=='S')y--;
        else if(d=='W'){
          x--;
        }

        string loc = to_string(x)+","+to_string(y);
        if(seen.find(loc)!= seen.end())
        return 1;

        seen.insert(loc);
      }
      return 0;
    }
};