#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int k,int sum)
{
	int num =1;
	int largestSum =0;
	for(int i=0;i<n;i++)
	{
		largestSum+=arr[i];
		
		if(largestSum>sum)
		{
			painters++;
			
			if(painters>k)
			{
				return false;
			}
			paintingTime = arr[i];
		}
	}
	return true;
}


int painterProblem(int arr[],int n,int k)
{
	int start =0;
	int end = arr[n-1];
	
	while(start<=end)
	{
		int mid=start+(end-start/)2;
		if(isPossible(arr,n,k,time))
		{
			
		}
		
	}
	
}


int main()
{
	
	
	return 0;
}
