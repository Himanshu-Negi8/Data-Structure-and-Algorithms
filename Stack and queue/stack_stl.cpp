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
