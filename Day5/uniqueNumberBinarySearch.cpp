#include<iostream>
using namespace std;

int uniqueNumber(int arr[],int start,int end )
{
	if(start>end)
	{
		return -1;
	}
	 int mid = start+(end-start)/2;
	 
	 if(arr[mid]!=arr[mid+1] and arr[mid]!=arr[mid-1])
	 {
	 	return arr[mid];
	 }
	 if(arr[mid]==arr[mid+1])
	 {
	 	int dist = mid-start;
	 	if(dist&1)
	 	{
	 		return uniqueNumber(arr,start,mid-1);
		}
		else
		{
			return uniqueNumber(arr,mid+2,end);
		}
	 }
	 
	 if(arr[mid]==arr[mid-1])
	 {
	 	int dist = mid-start+1;
	 	if(dist&1)
	 	{
	 		return uniqueNumber(arr,start,mid-2);
		}
		else
		{
			return uniqueNumber(arr,mid+1,end);
		}
	 }
	 
	
}


int main()
{
	int arr[11]={1,1,2,2,3,4,4,5,5,6,6};
	int n =11;
	cout<<uniqueNumber(arr,0,n-1);
	return 0;
}
