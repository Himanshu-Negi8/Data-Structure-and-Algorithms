#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int data,int si)
{
	if(si==n)
	{
		return -1;
	}
	
	if(data==arr[si])
	{
		return si;
	}
	return  linearSearch(arr,n,data,si+1);

}

int main()
{	
	int arr[]={1,4,2,4,3};
	cout<<linearSearch(arr,5,10,0)<<endl;
	return 0;
}
