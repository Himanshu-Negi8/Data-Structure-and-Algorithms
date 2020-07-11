#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n){
	if(n==1) return false;
	
	if(n==2) return true;
	
	if(n%2==0) return false;
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	int l,r;
	cin>>l>>r;
	
	for(;l<=r;l++){
		if(isPrime(l)){
			cout<<l<<" ";
		}
	}
	return 0;
}
