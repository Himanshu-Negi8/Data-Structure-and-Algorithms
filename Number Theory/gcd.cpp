#include<bits/stdc++.h>
using namespace std;

// complexity is O(min(a,b))
int gcdBruteForce(int a,int b){
	int ans=1;

	for(int i=1;i<=a and i<=b ; i++){
		if(a%i==0 and b%i==0){
			ans=i;
		}
	}
	return ans;
}

// better approach is eucild algorithm
int gcd(int a,int b){
	
	return b==0 ? a: gcd(b,a%b); 
	/*
		above can be written as 
		//base-case
		if(b==0){
			return a;
		}
		//recursive case 
		return gcd(b,a%b);
	*/
}

int lcm(int a, int b){
	return a*b/gcd(a,b);
}

int main(){
	
	int a,b;
	cin>>a>>b;
//	cout<<gcdBruteForce(a,b);
	cout<<gcd(a,b)<<endl;
	cout<<lcm(a,b)<<endl;
	return 0;
}
