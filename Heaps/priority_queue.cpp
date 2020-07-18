#include<bits/stdc++.h>
using namespace std;


int main(){
	
	
	//maxHeap declaration
	priority_queue<int>pq;
	
	int arr[10] = {5,6,7,7,89,7,1,2,4,10};
	
	for(int i=0;i<10;i++){
		pq.push(arr[i]);
	}
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
	cout<<endl;
	//minHeap declaration
	
	priority_queue<int,vector<int>,greater<int>>min_pq;
	
	min_pq.push(90);
	min_pq.push(100);
	min_pq.push(1);
	min_pq.push(2);
	min_pq.push(0);
	while(!min_pq.empty()){
		cout<<min_pq.top()<<" ";
		min_pq.pop();
	}
	return 0;
}
