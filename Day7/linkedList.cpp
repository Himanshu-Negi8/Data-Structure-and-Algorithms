#include<iostream>
#include<climits>
#include<math.h>
using namespace std;


class node{
	public:
		int data;
		node*next;
	
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


void insertAtHead(node*&head,int data) // insert at start
{
	node*n = new node(data);
	n->next=head;
	head =n;
}

void insertAtEnd(node*&head,int data) // insert at end
{
	if(head==NULL)
	{
		insertAtHead(head,data);
	}
	
	node *n = new node(data);
	node*temp = head;
	n->next = NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}
void display(node*head) // display the data of nodes
{
	node*temp =head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<"***************"<<endl;
}
void insertAtPosition(node*&head,int data,int pos) // insert at the specific position
{
	if(pos<=1)
	{
		insertAtHead(head,data);
	}
	else
	{
		node *temp = head;
		int i=1;
		while(++i<pos)
		{
			temp=temp->next;
			i++;
		}
		node*newNode = new node(data);
		newNode->next = temp->next;
		temp->next =newNode;
	}
}
int findLength(node*head) // length of the linked list
{
	node*temp = head;
	int i=0;
	while(temp!=NULL)
	{   
		++i;
		temp=temp->next;
	}
	return i;
}
int middlePoint(node*head) // return the integer value of a middle point
{
	int j = findLength(head);
	j = j/2;
	node*temp = head;
	for(int i=0;i<j-1;i++)
	{
		temp=temp->next;
	}
	return temp->data;
}

int kthElementFromLast(node*head,int k) // kth element from last
{
	node*temp =head;
	int i = findLength(head);
	i=abs(i-k);
	while(i>0)
	{
		temp=temp->next;
		i--;
	}
	
	return temp->data;
}
void deleteFromHead(node*&head) // delete from head
{
	if(head==NULL)
	{
		
	}

		node*temp=head;
		head = head->next;
		delete temp;
	
}

void deleteFromTail(node*&head) // delete from tail
{
	if(head==NULL)
	{
		cout<<"nothing to delete"<<endl;
	}
	else if(head->next==NULL)
	{
		deleteFromHead(head);
	}
	else
	{
		node *temp;
		temp=head;
		while(temp->next->next!=NULL)
		{
		
			temp=temp->next;
		}
		node*toBeDeleted = temp->next;
		temp->next = NULL;
		delete toBeDeleted;
	}
}
void deleteAtIdx(node*&head,int idx) // delete at a particular index 
{
	if(idx<=1)
	{
		deleteFromHead(head);
	}
	if(idx>=findLength(head))
	{
		deleteFromTail(head);
	}
	int steps =1;
	node*temp =head;
	while(steps<idx-1)
	{
		steps++;
		temp =temp->next;
	}
	node *toBeDeleted  = temp->next;
	temp->next = temp->next->next;
	delete toBeDeleted;
}

void reversePrint(node*p) // print in reverse order 
{
	if(p==NULL)
	{
		return;
	}
	reversePrint(p->next); 
	cout<<p->data<<endl;
}

bool searchRecursive(node*p,int data) // search for an item recursively
{
	if(p==NULL)
	{
		return false;
	}

	if(p->data==data)
		{
			return true;
		}
	else
	{
		return searchRecursive(p->next,data);
	}
		
}

node* reverseRecursive(node*head) // reverse using recursion
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node*newHead = reverseRecursive(head->next);
	node*currentHead = head;
	currentHead->next->next = currentHead;
	currentHead->next = NULL;
	return newHead;
}

void reverse(node*&p) // reverse the list iteratively
{
	node*prev,*next,*current=p;
	while(current!=NULL)
	{
		next = current->next;
		current->next=prev;
		prev=current;
		current =next;
	}
	p = prev;
}

node*middleNode(node*head) //returns the complete middle node
{
	node*p=head;
	node*q = head;
	
	
	while(q->next!=NULL and q->next->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
	}
	return p;
}



node*merge(node*a,node*b)
{
	if(a==NULL)
	{
		return a;
	}
	if(b==NULL)
	{
		return b;
	}
	node*c;
	if(a->data<=b->data)
	{
		c=a;
		c->next = merge(a->next,b);
	}
	else{
		c=b;
		c->next = merge(a,b->next);
	}
	return c;
	
}

node* mergeSort(node*head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node*mid = middleNode(head); 
	
	node*a = head;
	node*b = mid->next;
	mid->next=NULL;
	
	a=mergeSort(a);
	b=mergeSort(b);
	node*c = merge(a,b);
	return c;
}






node*kReverse(node*head,int k)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	
	
	node*curr =head;
	node*prev =NULL;
	int count=1;
	while(count<=k and curr!=NULL)
	{
		node*n = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr=n;
		count++;
	}
	head->next = kReverse(head,k);
}

int main()
{
//	node*head = NULL;  
//	insertAtHead(head,10);
//	insertAtHead(head,20);
//	insertAtHead(head,30);
//	insertAtHead(head,40);
//	insertAtHead(head,50);
//	insertAtPosition(head,345,1);
//	insertAtPosition(head,45,2);
//	insertAtEnd(head,23);
//	insertAtEnd(head,567);
//	display(head);
//	
//	cout<<"Length is : "<<findLength(head)<<endl;
//	cout<<"Middle Point is :"<<middleNode(head)->data<<endl;
//	cout<<"kthElementfromLast : "<<kthElementFromLast(head,3)<<endl;
//	deleteFromHead(head);
//	
//	display(head);
//	deleteFromTail(head);
//	display(head);
//	deleteAtIdx(head,4);
//	display(head);
////	reversePrint(head);
//	head = reverseRecursive(head);
//	cout<<searchRecursive(head,10);
	node* head1 = NULL;
	insertAtEnd(head1,1);
	insertAtEnd(head1,3);
	insertAtEnd(head1,5);
	insertAtEnd(head1,7);
	insertAtEnd(head1,8);
	insertAtEnd(head1,10);

	node* head2 = NULL;
	insertAtEnd(head2,2);
	insertAtEnd(head2,4);
	insertAtEnd(head2,6);
	
	node* mergesList = merge(head1,head2);
	display(mergesList);
	return 0;
}

/*
Reverse a linked list either by recursion and iterative approach

*/
