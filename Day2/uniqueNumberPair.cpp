#include<iostream>
using namespace std;


void uniqueNumberPair(int arr[],int n)
{
	int XorPair = arr[0];
	for(int i=0;i<n;i++)
	{
		XorPair^=arr[i];
	}
	if(XorPair==0)
	{
		return;
	}
	
	int var =XorPair;
	int position =0;
	
	while(true)
	{
		if(var&1)
		{
				break;
		}
		position++;
		var = var>>1;
	
		
	}
	int check = XorPair;
	for(int i=0;i<n;i++)
	{
		int element = (arr[i]>>position);
		if(element&1)
		{
			check =check^arr[i];
		}
		
	}
	cout<<check<<endl;
}

int main()
{
	
	int arr[]={1,1,2,2,3,3,4,5,5,6,6};
	int n =11;
	uniqueNumberPair(arr,n);
	return 0;
}
