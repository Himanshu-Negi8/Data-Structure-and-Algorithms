#include<iostream>
using namespace std;

bool isSorted(int arr[],int n,int si)
{
	if(si==n-1)
	{
		return true;
	}
	if(arr[si]>arr[si+1]){
		return false;
	}
	
	bool rest_of_thearray = isSorted(arr,n,si+1);
	
	return rest_of_thearray;
}



int main()
{
	int arr[]= {1,2,3,4,5,6};
	cout<<isSorted(arr,6,0);
	return 0;
}







