#include<bits/stdc++.h>
using namespace std;



int main(){
	
	queue<int>q;
	
	for(int i=1;i<=10;i++){
		q.push(i*i);
	}
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
