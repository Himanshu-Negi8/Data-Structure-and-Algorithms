#include<bits/stdc++.h>
using namespace std;

bool partitionEqualSumSubset(int arr[],int n,int si,int sum,int total){
	if(sum==total){
		return true;
	}

	if(sum>total or si>=n){
		return false;
	}

	bool include = partitionEqualSumSubset(arr,n,si+1,sum+arr[si],total);
	bool exclude = partitionEqualSumSubset(arr,n,si+1,sum,total);

	return exclude||include;
}

bool isPossible(int arr[],int n){
	int total = 0;

	for(int i=0;i<n;i++){
		total+=arr[i];
	}

	if(total&1){
		return false;
	}

	return partitionEqualSumSubset(arr,n,0,0,total/2);
}


int main()
{ 
  int []a = {1,5,5,11};
	return 0;
}
