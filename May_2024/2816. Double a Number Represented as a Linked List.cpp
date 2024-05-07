Question :: 2816. Double a Number Represented as a Linked List

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Complexity:
Time complexity:
    O(N)
Space complexity:
    O(1)
Code :
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
class Solution {
    ListNode* reverse(ListNode *head){
        if(!head)return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(head){
            curr= head->next;
            head->next= prev;
            prev= head;
            head = curr;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head =reverse(head);
        int carry =0;
        ListNode* temp=head;
        while(head){
            int v = head->val*2 + carry;
            carry =v/10;
            head->val = v%10;
            if(head->next==NULL){
                while(carry){
                    ListNode * n = new ListNode(carry);
                    head->next=n;
                    carry/=10;
                    head = head->next;

                }
            }
            head = head->next;
        
        }
      
        return reverse(temp);
    }
};