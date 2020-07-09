#include<bits/stdc++.h>
using namespace std;




//root n time
bool isPrime(int num){
	
	if(num==1){
		return false;
	}
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}

//little optimization checking for even and odd divisability if yes return false otherwise true

bool checkPrime(int num){
	if(num==1) return false;
	if(num==2) return true;
	
	if(num%2==0) return false;
	
	for(int i=3;i*i<=num;i+=2){
		if(num%i==0) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	
//	if(isPrime(n)){
//		cout<<"Yes";
//	}else{
//		cout<<"No";  
//	}
	
	if(checkPrime(n)){
		cout<<"Yes";
	}else{
		cout<<"No";  
	}
	
	return 0;
}
