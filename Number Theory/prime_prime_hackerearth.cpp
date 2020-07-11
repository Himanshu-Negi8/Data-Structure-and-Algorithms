#include<bits/stdc++.h>
using namespace std;



int arr[1000001];
int pp[1000001];
void sieve(){
	
	int maxN=1000000;
	arr[0]=arr[1]=0;
	arr[2]=1;
	
	
	// mark all odd number as prime 
	for(int i=3;i<=maxN;i+=2){
		arr[i]=1;
	} 
	
	//sieve logic to mark non-prime number as zero
	//1.optimisation : iterate only over odd numbers
	for(int i=3;i<=maxN;i+=2){
		
		if(arr[i]){
			// mark all the multiples of that number as not prime
			// 2.optimisation take a jump of 2i from i*i
			for(int j=i*i;j<=maxN;j+=2*i){
				arr[j]=0;
				
			}
		}
	}
	
	int count=0;
	for(int i=0;i<=maxN;i++){
		if(arr[i]){
			count++;
		}
		
		if(arr[count]==1){
			pp[i]=1;
		}else{
			pp[i]=0;
		}
	}
	
	
}


int main(){
	sieve();
	int l,r,t;
	cin>>t;
	
	while(t--){
		cin>>l>>r;
		int count=0;
		
		for(;l<=r;l++){
			count+=pp[l];
		}
		cout<<count<<endl;
	}
	return 0;
}
