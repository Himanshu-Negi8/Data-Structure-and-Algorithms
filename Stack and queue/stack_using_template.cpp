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
