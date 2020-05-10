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
public:
    ListNode*reversed(ListNode*head){
        ListNode*prev=NULL;
        while(head){
            ListNode*temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode*fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow =slow->next;
            fast=fast->next->next;
        }
        
        slow = reversed(slow);
       
        
        while(slow) {
        if(slow->val != head->val) {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
        
    }
};
