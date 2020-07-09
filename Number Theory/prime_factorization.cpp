#include<bits/stdc++.h>
using namespace std;



//brute force approach

void primeFactors(int num){
	if(num==0 || num==1){
		cout<<"No"<<endl;
	}
	
	else{
		
		for(int i=2;i<=num;i++){
			if(num%i==0){
				int cnt=0;
				while(num%i==0){
					cnt++;
					num/=i;
				}
				cout<<i<<"^"<<cnt<<endl;
			}
		}
	}
	
}

//optimized approach

void primeFactor(int num){
	if(num==0 || num==1){
		cout<<"No"<<endl;
	}
	
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			int cnt=0;
			while(num%i==0){
				cnt++;
				num/=i;
			}
			cout<<i<<"^"<<cnt<<endl;
		}
	}
	//for prime numbers like 7 as prime number has no prime factors itself 
	if(num>1){
		cout<<num<<"^"<<1<<endl;
	}
	
}

int main(){
	int n;
	cin>>n;
	
//	primeFactors(n);
	primeFactor(n);
	
	
	return 0;
}
