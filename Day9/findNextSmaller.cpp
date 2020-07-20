#include<iostream>
#include<stack>
using namespace std;
void nextSmaller(int arr[],int n)
{
		stack <int>s;
		
		
		for(int i=0;i<n;i++)
		{
			while(!s.empty() and arr[i]<=arr[s.top()])
			{
			 int idx = s.top();
			 s.pop();
			 cout<<arr[idx]<<"->"<<arr[i]<<endl;
			 
			}
			
			s.push(i);
			
		
		}
		while(!s.empty())
		{
			int idx = s.top();
			s.pop();
			cout<<arr[idx]<<"->"<<(-1)<<endl;
		}
		
}
int main()
{
	int arr[]={5,3,10,2,6,13,4};
	nextSmaller(arr,7);
	return 0;
}
