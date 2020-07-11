#include<bits/stdc++.h>
using namespace std;


int arr[1000001];

void sieve(){
	
	int maxN=1000000;
	
	for(int i=1;i<=maxN;i++) arr[i]=-1;

	for(int i=2;i<=maxN;i++){
		if(arr[i]==-1){
				for(int j=i;j<=maxN;j+=i){
					if(arr[j]==-1){
						arr[j]=i;
						
					}
				}
		}
	}
	return;
}

void prime_factors(int num){
	
	cout<<"Prime factors will be : ";
	while(num>1){
		
		cout<<arr[num]<<" ";
		num/=arr[num];
	}
}

int main(){
	sieve();
	int num;
	cin >> num;
	prime_factors(num);
	return 0;
}
