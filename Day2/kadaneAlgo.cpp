#include<iostream>
using namespace std;

int main()
{
	int arr[4]={1,2,-2,-5};
	int max_till_now =0;
	int max_previous =0;
	for(int i=0;i<4;i++)
	{
		max_till_now = max_till_now+arr[i];
		if(max_till_now<0)
		{
			max_till_now=0;
		}
		if(max_previous<max_till_now)
		{
			max_previous=max_till_now;
		}
	}
	cout<<max_previous;
	
	return 0;
}
