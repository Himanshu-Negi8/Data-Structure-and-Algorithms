#include<iostream>
using namespace std;

void sortArray(int *arr,int n)
{
	if(n<0)
	{
		return;
	}
	
	if(arr[n]<arr[n-1])
	{
		int temp = arr[n];
		arr[n]=arr[n-1];
		arr[n-1] = temp;
		sortArray(arr,n-1);
	}
}

int main()
{
	int arr[]={3,5,2,1,6};
	sortArray(arr,5);
	cout<<arr<<endl;
	return 0;
}
