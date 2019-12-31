#include<iostream>
using namespace std;


int main()
{
	int arr[]={0,2,1,3,0,1,2,1,2,1}; // array representing the height of the buildings
	int n=10,sum; 
	int l[n], r[n]={0}; // left most height and right most height array
	
	for(int i=0;i<n;i++)
	{
		l[i]=r[i]=arr[i];
		
	}
	for(int i=1;i<n;i++)
	{
		if(l[i-1]>l[i])
		{
			l[i]=l[i-1];
		}
		else
		{
			l[i]=arr[i];
		}
		
	}
	
	for(int i=n-2;i>=0;i--)
	{
		if(r[i]>r[i+1])
		{
			r[i]=r[i];
		}
		else
		{
			r[i]=r[i+1];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=min(l[i],r[i])-arr[i];
	}
	cout<<sum<<endl;
	return 0;
}
