#include<bits/stdc++.h>
using namespace std;

/* 
 making push operation costly because new item is always added in empty q2 then 
 copying every time from q1 to q2 and then swap q1 and q2 so that new item remain in front of q1 always
*/
class Stack{
	
	int cur_size;
	queue<int>q1,q2;
public:
	Stack(){
		cur_size=0;
	}
	void push(int x){
		
		cur_size++;
		q2.push(x);
		
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		
		swap(q1,q2);
		
	}
	void pop(){
		if(cur_size==0){
			return;
		}
		q1.pop();
		cur_size--;
		return;
		
	}
	
	int top(){
		if(q1.empty()){
			return -1;
		}
		return q1.front();
	}
	int size(){
		return cur_size;
	}
	
	void display(){
		if(q1.empty()) return;
		
		
		
		while(!q1.empty()){
			cout<<q1.front()<<" ";
			q2.push(q1.front());
			q1.pop();
		}
		swap(q1,q2);
		cout<<endl;
	}
	
		
};

int main(){
	
	Stack s;
	s.push(1);
	s.push(3);
	s.push(5);
	cout<<"Size is "<<s.size()<<endl;
	cout<<"Top element :"<<s.top()<<endl;
	s.pop();
	cout<<"Display :";
	s.display();
	cout<<s.top();
	return 0;
}




