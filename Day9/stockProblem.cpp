#include <bits/stdc++.h>

using namespace std;

class Stack{
	int top;
	int *arr;
	int maxSize;
public:
	Stack(int default_size=5){
		this->maxSize = default_size;
		this->top = -1;
		this->arr = new int[this->maxSize];
	}

	void push(int data){
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

	int getTop(){
		return this->arr[this->top];
	}
};

void findSteps(int arr[],int n)
{
	Stack s(n);

	s.push(0);
	for(int i=1;i<n;i++)
	{
		
	
		while(!s.isEmpty() and arr[s.getTop()]<=arr[i])
		{
			s.pop();
		}
	
		int value;
		if(s.isEmpty()){
			value+=1;
		} 
		else{
			value = i-s.getTop();
		}
		cout<<value<<" ";
		s.push(i);
	}
	
}

void findGreater(int arr[],int n) //next greater element
{
		Stack s(n);
		
		
		for(int i=0;i<n;i++)
		{
			while(!s.isEmpty() and arr[i]>=arr[s.getTop()])
			{
			 int idx = s.getTop();
			 s.pop();
			 cout<<arr[idx]<<"->"<<arr[i]<<endl;
				
			}
			
			s.push(i);
			
		
		}
		while(!s.isEmpty())
		{
			int idx = s.getTop();
			s.pop();
			cout<<arr[idx]<<"->"<<(-1)<<endl;
		}
		
}
int main(){

	int arr[]={100,80,60,70,60,75,85};

	findSteps(arr,7);

//	int arr[]={5,3,10,2,6,13,4};
//	findGreater(arr,7);
	return 0;
}
