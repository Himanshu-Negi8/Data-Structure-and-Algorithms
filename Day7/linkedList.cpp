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

void display(node*head)
{
	node*temp =head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int main()
{
	node*head = NULL;  
	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);
	display(head);
	return 0;
}
