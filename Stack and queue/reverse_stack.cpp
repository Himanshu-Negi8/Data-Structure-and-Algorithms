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


