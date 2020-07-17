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
	void heapify(int index){
		int left = 2*index;
		int right = 2*index+1;
		//assume current index is min
		int minIndex = index;
		
		if(left<v.size() and compare(v[left],v[index])){
			minIndex =left;
			
		}
		if(right<v.size() and compare(v[right],v[minIndex])){
			minIndex=right;
		}
		if(minIndex!=index){
			swap(v[index],v[minIndex]);
			heapify(minIndex);
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
		
		void pop(){
			//remove top most element
			int last = v.size()-1;
			swap(v[1],v[last]);
			v.pop_back();
			heapify(1);
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
	//false for maxheap and true for minHeap
	Heap h(false);
	h.push(10);
	h.push(9);
	h.push(17);
	h.push(-78);
	h.push(1);
	h.push(98);
//	cout<<h.top();
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}
	
	return 0;
}