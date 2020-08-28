#include<bits/stdc++.h>
using namespace std;

int computeCost(int arr[],int n,int i){
	if(i==n-1) return 0;
	
	if(i>=n) return INT_MAX;
	
	int left = abs(arr[i]-arr[i+1])+computeCost(arr,n,i+1);
	
	int right = INT_MAX;
	
	if(i+2<n){
		right = abs(arr[i]-arr[i+2])+computeCost(arr,n,i+2);
		
	}
	
	return min(left,right);
	
}


int main(){
	
	
	int n;
	cin>>n;
	
	int*arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int ans = computeCost(arr,n,0);
	cout<<ans;
	
	
	return 0;
	
}
