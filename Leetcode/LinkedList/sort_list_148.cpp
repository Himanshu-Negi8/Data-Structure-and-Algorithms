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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==0){
            return l2;
        }
        if(l2==0){
            return l1;
        }
        ListNode*l3;
        if(l1->val<=l2->val){
            l3 = l1;
            l3->next = mergeTwoLists(l1->next,l2);
        }else{
            l3=l2;
            l3->next = mergeTwoLists(l1,l2->next);
        }
        return l3;
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==0 or head->next==0) return head;
        
        ListNode*slow = head;
        ListNode*fast=head->next;
        
        while(fast!=0 and fast->next!=0){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*temp = slow->next;
        slow->next=0;
        
        ListNode*l1 = sortList(head);
        ListNode*l2 = sortList(temp);
        
        return mergeTwoLists(l1,l2);
        
    }
};
