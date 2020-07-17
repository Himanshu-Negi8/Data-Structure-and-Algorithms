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
