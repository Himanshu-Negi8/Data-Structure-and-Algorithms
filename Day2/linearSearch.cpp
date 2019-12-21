#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int data,int si)
{
	if(si==n-1)
	{
		return si;
	}
	
	if(data==arr[si])
	{
		return si;
	}
	int rest_of_the_array = linearSearch(arr,n,data,si+1);
	if(rest_of_the_array<0)
	{
		return -1;
	}
	
}

int main()
{	
	int arr[]={1,4,2,4,3};
	cout<<linearSearch(arr,5,3,0)<<endl;
	return 0;
}
