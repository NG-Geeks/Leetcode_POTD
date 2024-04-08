Question ::1700. Number of Students Unable to Eat Lunch

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
 
Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(1)

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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0, zeroes = 0;
        for(int i : students) {
            
            ones += i;
        }
        zeroes = students.size() - ones;
        
        for(int i = 0; i < sandwiches.size(); i++) {
            
            int val = sandwiches[i];
            if(val == 0) {
                
                if(zeroes == 0) {
                    
                    return sandwiches.size() - i;
                }
                zeroes--;
            } else {
                
                if(ones == 0) {
                    
                    return sandwiches.size() - i;
                }
                ones--;
            }
        }
        
        return 0;
    }
};
