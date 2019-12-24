#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int k,int time)
{
	int painters =1;
	int paintingTime =0;
	for(int i=0;i<n;i++)
	{
		paintingTime+=arr[i];
		
		if(paintingTime>time)
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
	int ans =0;
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(isPossible(arr,n,k,mid))
		{
			ans =mid;
			start =mid+1;
			
		}
		else 
		{
			end = mid-1;
		}
		
	}
	return ans;
}


int main()
{
	int arr[4]={10,20,30,40};
	int n=4;
	int k=2;
	cout<<painterProblem(arr,4,2)<<endl;
	
	return 0;
}
