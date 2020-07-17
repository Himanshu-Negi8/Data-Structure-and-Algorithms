#include<bits/stdc++.h>
using namespace std;


//pop expensive 

class Stack{
	
	int cur_size;
	queue<int>q1,q2;
public:
	Stack(){
		cur_size=0;
	}
	void push(int item){
		q1.push(item);
		cur_size++;
	}
	
	void pop(){
		if(q1.empty()){
			return ;
		}
		
		while(q1.size()!=1){
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		cur_size--;
		swap(q1,q2);
	}
	int size(){
		return cur_size;
	}
	int top(){
		if(q1.empty()){
			return -1;
		}
		while(q1.size()!=1){
			q2.push(q1.front());
			q1.pop();
		}
		int temp = q1.front();
		q1.pop();
		q2.push(temp);
		swap(q1,q2);
		return temp;
	}
	
};


int main(){
	
	Stack obj;
	obj.push(1);
	obj.push(34);
	obj.push(35);
	cout<<obj.top();
	obj.pop();
	cout<<" "<<obj.top();
	return 0;
}
