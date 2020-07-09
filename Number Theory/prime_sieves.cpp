#include<bits/stdc++.h>
using namespace std;

vector<int>v;


void primeSieve(int *p,int n){
	p[0]=p[1]=0;
	p[2]=1;
	
	
	// mark all odd number as prime 
	for(int i=3;i<=n;i+=2){
		p[i]=1;
	} 
	
	//sieve logic to mark non-prime number as zero
	//1.optimisation : iterate only over odd numbers
	for(int i=3;i<=n;i+=2){
		
		if(p[i]){
			// mark all the multiples of that number as not prime
			// 2.optimisation take a jump of 2i from i*i
			for(int j=i*i;j<=n;j+=2*i){
				p[j]=0;
				
			}
		}
	}
	
	
	return;
}

int main(){
	
	int N = 1000000;
	int p[N]={0};
	int num;
	cin>>num;
	primeSieve(p,num);
	for(int i=0;i<=num;i++){
		if(p[i]){
			cout<<i<<" ";
		}
	} 
	
}
