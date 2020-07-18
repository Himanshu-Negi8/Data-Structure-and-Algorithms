#include<bits/stdc++.h>
using namespace std;


// for printing the k largest element

void query_print(priority_queue<int,vector<int>,greater<int>>pq){
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}


/*
logic is used to minHeap instead of maxHeap as it is running stream so we can't store all 
element to process k best elements.

why using minHeap? - as we have to give best k elements we will create a minHeap so whenver
 we have reached current size as  k  we just pop the first element and push the new number as popped item  
 will also not contibute further to best 
 k elements 
*/
int main(){
	
	priority_queue<int,vector<int>,greater<int>>pq;
	
	int no;
	int cs =0;
	int k=4;
	//to find k largest number query set
	while(scanf("%d",&no)!=EOF){
		if(no==-1){
			query_print(pq);
		}else if(cs<k){
			pq.push(no);
			cs++;
		}else{
			if(no>pq.top()){
				pq.pop();
				pq.push(no);
				// here we are not increasing the current size beacuse both  pop and push are performed 
			}
		}
	}
	return 0;
}
