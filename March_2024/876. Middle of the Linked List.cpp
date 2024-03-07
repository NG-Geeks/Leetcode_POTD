Question :: 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 
Solution::

Complexity::

Time complexity : O(N)

Space complexity : O(1)

 Code::
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #pragma gcc optimize("03")
 auto init = [](){
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     return 'c';
 }();
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
            ListNode * slow  = head;
        ListNode * fast  = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow= slow->next;
        }
        return slow;
    }
};
