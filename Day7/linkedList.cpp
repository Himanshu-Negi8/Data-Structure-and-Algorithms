#include<iostream>
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

void insertAtHead(node*&head,int data)
{
	node*n = new node(data);
	n->next=head;
	head =n;
}

void insertAtEnd(node*head,int data)
{
	node *n = new node(data);
	node*temp = head;
	n->next = NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
}
void display(node*head)
{
	node*temp =head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int findLength(node*head)
{
	node*temp = head;
	int i=0;
	while(temp!=NULL)
	{++i;
		temp=temp->next;
	}
	return i;
}
int main()
{
	node*head = NULL;  
	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);
	insertAtEnd(head,20);
	display(head);
	cout<<findLength(head);
	return 0;
}
