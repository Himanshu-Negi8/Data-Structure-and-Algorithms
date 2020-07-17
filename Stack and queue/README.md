
```c
#include<bits/stdc++.h>
using namespace std;


class Stack{
	
	private:
		vector<int>v;
	public:
		void push(int data){
			v.push_back(data);
		}
		bool empty(){
			return v.size()==0;
		}
		void pop(){
			if(!empty()){
				v.pop_back();
			}
		}
		int top(){
			return v[v.size()-1];
		}
};
int main(){
	Stack obj;
	
	for(int i=1;i<=5;i++){
		obj.push(i*i);
	}
	
	while(!obj.empty()){
		cout<<obj.top()<<" ";
		obj.pop();
	}
	
	return 0;
}


```

---

# Stack generic template

```c
#include<bits/stdc++.h>
using namespace std;


//generalizing the code for all data types 

template<typename T>
class Stack{
	private:
		vector<T>v;
	public:
		void push(T data){
			v.push_back(data);
		}
		bool empty(){
			return v.size()==0;
		}
		void pop(){
			if(!empty()){
				v.pop_back();
			}
		}
		T top(){
			return v[v.size()-1];
		}
};

int main(){
	
	
	Stack <char>obj;
	
	for(int i=65;i<=70;i++){
		obj.push(i);
	}
	
	while(!obj.empty()){
		cout<<obj.top()<<" ";
		obj.pop();
	}
	return 0;
}

```

---

# Stack using STL

```c
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	stack<string>s; //stack<T>obj, T can be anything int char string ...
	s.push("apple"); //push takes an argument of type T
	s.push("banana");
	s.push("guava");
	
	//empty function returns true if stack is empty or we can say top is at -1
	
	while(!s.empty()){
		cout<<s.top(); //top is for getting element at peek 
		s.pop(); //removing from top
	}
	
	return 0;
}
```
---

# Reverse Stack

```c
#include<bits/stdc++.h>
using namespace std;

void transfer(stack<char>&s1,stack<char>&s2,int n){
	
	for(int i=0;i<n;i++){
		s2.push(s1.top());
		s1.pop();
	}
	
}

void reverseStack(stack<char>&s1){
	stack<char>s2;
	int n = s1.size();
	
	for(int i=0;i<n;i++)
	{
		char ch = s1.top();
		s1.pop();
		transfer(s1,s2,n-i-1);
		s1.push(ch);
		transfer(s2,s1,n-i-1);
	}
	
}


void insertBottom(stack<char>&s,char ch){
	
	if(s.empty()){
		s.push(ch);
		return;
	}
	char c = s.top();
	s.pop();
	insertBottom(s,ch);
	s.push(c);
}

void reverseStackRec(stack<char>&s){
	
	if(s.empty()) return;
	
	char ch = s.top();
	s.pop();
	reverseStackRec(s);
	insertBottom(s,ch);

	
}
int main(){
	
	stack<char>s;
	
	for(int i=65;i<69;i++){
		s.push(i);
	}
	reverseStackRec(s); // recursive approach
	//revserseStack(s); one extra stack aprroach 
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}


/*
	worst-case approach 
	
	int n =s1.size();
	transfer(s1,s2,n);
	transfer(s2,s3,n);
	transfer(s3,s,n);
	
*/




```

---
---

# Queue circular 

```c
#include<bits/stdc++.h>
using namespace std;

//generic circular queue

template<typename T>

class Queue{
	T*arr;
	int f;
	int r;
	int ms;
	int cs;
public:
	Queue(int ds=4){
		f=0;ms=ds;
		r=ms-1;
		arr = new T[ms];
		cs=0;
	}
	
	bool isFull(){
		return cs==ms;
	}
	
	bool isEmpty(){
		return cs==0;
	}
	
	//pushes the data at rear+1
	void push(T data){
		if(!isFull()){
			r =(r+1)%ms;
			arr[r]=data;
			cs++;
		}
	}
	void pop(){
		if(!isEmpty()){
			f=(f+1)%ms;
			cs--;
		}
	}
	T getFront(){
		return arr[f];
	}
};
int main(){
	
	Queue<int>q(10);
	
	for(int i=1;i<=6;i++){
		q.push(i);
	}
	q.pop();
	q.push(10);
	
	while(!q.isEmpty()){
		cout<<q.getFront()<<" ";
		q.pop();
	}
	return 0;
}
```



