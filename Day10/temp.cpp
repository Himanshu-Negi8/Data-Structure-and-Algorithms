#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		cout<<arr[i]<<endl;
	}
	return 0;
}
