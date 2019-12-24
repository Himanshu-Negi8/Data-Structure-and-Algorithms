#include<iostream>
using namespace std;

int searchRotatedArray(int arr[],int start,int end,int n)
{
	
	
	
	while(start<=end)
	{
		int mid =(start+end)/2;
		
		if(!arr[mid]<arr[mid+1])
		{
			return mid-1;
		}
		
		
	}
}

int main()
{
	 int arr[7] = {6,7,1,2,3,4,5};
	 cout<<searchRotatedArray(arr,0,7,7);
	return 0;
}
