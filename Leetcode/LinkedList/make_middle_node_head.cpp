class Solution{
	void updateHead(ListNode*head){
		
		ListNode*slow =head;
		ListNode*fast = head;
		ListNode*prev=NULL;
		
		
		while(fast!=NULL and fast->next!=NULL){
			prev=slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		
		prev->next = prev->next->next;
		slow->next = *head;
		*head = slow;
		
	}
	
	
};
