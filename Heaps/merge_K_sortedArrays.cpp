#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>a,vector<int>b,vector<int>c,int n){
	
	priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
	
	
	vector<int>v(n);
	int i=0,j=0,k=0;
	// push operation for every first element of k arrays
	pq.push(make_pair(a[i++],'a'));
	pq.push(make_pair(b[j++],'b'));
	pq.push(make_pair(c[k++],'c'));
	
	
	//pair check can be increase accroding to k size just cut or copy paste if-else logic if number of 
	//array increase or decrease 
	
	
	for(int p=0;p<n;p++){
		
		auto m = pq.top();
		v.insert(v.begin()+p,pq.top().first);
		pq.pop();
		if(m.second=='a'){
			
			if(i<a.size()){
				pq.push((make_pair(a[i++],'a')));
			}else{
				pq.push(make_pair(INT_MAX,'a'));
			}
		}
		
		else if(m.second=='b'){
			
			if(j<b.size()){
				pq.push((make_pair(b[j++],'b')));
			}else{
				pq.push(make_pair(INT_MAX,'b'));
			}
		}else if (m.second=='c'){
			
			if(k<c.size()){
				pq.push((make_pair(c[k++],'c')));
			}else{
				pq.push(make_pair(INT_MAX,'c'));
			}
		
		}
		
	}
	
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}





int main(){
	
	vector<int>a{1,2,3,4,5};
	vector<int>b{0,0,1,2,23,90};
	
	vector<int>c{12,23,34,56};
	int n = a.size()+b.size()+c.size();
	

	merge(a,b,c,n);
	
	
	return 0;
}
