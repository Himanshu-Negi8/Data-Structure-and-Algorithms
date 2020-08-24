#include<iostream>
using namespace std;
/*
Program for finding first and last occurence of a number in array
using the binary search.
*/
int lastOccurence(int arr[],int n,int data)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid =(start+end)/2;
		if(arr[mid]==data)
		{
                        ans=mid;
			start=mid+1; //for last occurence
			
		}
		else if(arr[mid]>data)
		{
			end = mid-1;
		}
		else
		{
			start=mid+1;
		}
		
	}
	return ans;
}
int firstOccurence(int arr[],int n,int data)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	while(start<=end)
	{
		int mid =(start+end)/2;
		if(arr[mid]==data)
		{
			ans = mid;
			end = mid-1; //for first occurence
		
			
		}
		else if(arr[mid]>data)
		{
			end = mid-1;
		}
		else
		{
			start=mid+1;
		}
		
	}
	return ans;
}

int main()
{
	int arr[8] = {1,1,2,2,2,3,3,4}; 
	int n =8;
	cout<<lastOccurence(arr,n,2);
	
	return 0;
}
