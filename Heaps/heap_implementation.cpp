#include<bits/stdc++.h>
using namespace std;


class Heap{
	
	vector<int>v;
	bool minHeap;
	bool compare(int a,int b){
		if(minHeap){
			return a<b;
		}else{
			return a>b;
		}
	}
	public:
		Heap(bool type=true){
			minHeap=type;
			//block 0th index
			v.push_back(-1);
		}
		
		void push(int data){
			//insert at last
			v.push_back(data);
			
			//take_element to correct position 
			
			int index = v.size()-1;
			int parent = index/2;
			
			while(index>1 and compare(v[index],v[parent])){
				swap(v[index],v[parent]);
				index = parent;
				parent/=2;
			}
		}
		bool empty(){
			return v.size()==1;
		}
		int top(){
			if(!empty()){
				return v[1];
			}
			
		}
};



int main(){
	Heap h(true);
	h.push(10);
	h.push(9);
	h.push(17);
	h.push(-78);
	h.push(1);
	h.push(98);
	cout<<h.top();
	
	return 0;
}
