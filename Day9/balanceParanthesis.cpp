#include<iostream>
using namespace std;

template <typename T>
class Stack{
	int top;
	int maxSize;
	T *arr;
public:
		Stack(int default_size=5){
		this->maxSize = default_size;
		this->top = -1;
		this->arr = new T[this->maxSize];
	}

	void push(T data){
		if(this->top == this->maxSize - 1){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		this->top++;
		this->arr[top] = data;
	}

	int size(){
		return this->top + 1;
	}

	bool isEmpty(){
		return this->top==-1;
	}

	void pop(){
		if(this->top==-1){
			cout<<"Stack is empty"<<endl;
			return;
		}

		this->top--;
	}

	T getTop(){
		return this->arr[this->top];
	}
	
	

};
bool balanceParanthesis(string expr)
{
	Stack<char> s;
	for(int i=0;i<expr.length();i++)
	{
		if(expr[i]=='(')
		{
			s.push(expr[i]);
		}
		else
		{
			if(!s.isEmpty() and s.getTop()=='('){
				s.pop();
			}else{
				return false;
			}
		}
	}
	return s.isEmpty();
	
}
bool duplicateParanthesis(string expr)
{
	Stack<char> s;
	int count=0;
	for(int i=0;i<expr.length();i++)
	{
		if(expr[i]!=')')
		{
			s.push(expr[i]);
		}else{
			if(s.getTop()=='(')
			{
				return true;
			}
			while(s.getTop()!='(')
			{
				s.pop();
			}
			s.pop();
		}
	}
	return false;
}
int main()
{
	string s = "((())";
	string expr = "(((a+(b)))+(c+d))";
	cout<<balanceParanthesis(s)<<endl;
	cout<<duplicateParanthesis(expr)<<endl;
	return 0;
}
