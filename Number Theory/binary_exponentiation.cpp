#include<bits/stdc++.h>
using namespace std;

//calculation of a to the power b



//good for even power but what for odd powers ??
int power(int a, int b){
	if(!b) return 1;
	if(b==1) return a;
	
	int temp = power(a,b/2);
	int result = temp*temp;
	return result;
}

//recursive computation is always slow then the iterative computation

int powerSecond(int a, int b){
	if(!b) return 1;
	if(b==1) return a;
	
	int temp = power(a,b/2);
	int result = temp*temp;
	if(b%2==1)  result*=a; 
	return result;
}

int computePower(int a,int b){
	
	if(!b) return 1;
	if(b==1) return a;
	int result=1;
	
	while(b>0){
		if(b%2==1) result*=a;
	
		a*=a;
		b/=2;
				
	}
	
	return result;
	
}


//computePower second code can be like this also


int computePowerII(int base,int power){
	if(!power) return 1;
	if(power==1) return base;
	
	int res=1;
	while(power){
		if(power&1){
			res*=base; power--;
		}
		else{
			base*=base;
			power/=2;
		}
	}
	return res;
}


int main(){
	
	cout<<computePower(3,40);
	
//	int base=3;
//	int result=1;
//	for(int i=1;i<=512;i++){
//		result*=base;
//	}
//	cout<<result;

	return 0;
}
