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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int length =0;
        ListNode*temp = head;
        ListNode*dummy = head;
        while(temp){
            length++;
            temp=temp->next;
        }
        
        if(n==1 and length==1)
        {
            return NULL;
        }
        if(n==length){
           dummy = dummy->next;
            return dummy;
        }
        
        length-=n;
        temp=dummy;
        while(length>1){
            length--;
            temp=temp->next;
            
        }
        
        temp->next=temp->next->next;
        return dummy;
    }
};
