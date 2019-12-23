#include<iostream>
#include<climits>
using namespace std;


int main()
{
	int arr[4]={1,2,-3,4};
	int max_sum=0;
	int current_sum=0;
	
	for(int i=0;i<4;i++)
	{
		for(int j=i;j<4;j++)
		{
			current_sum=0;
			for(int k=i;k<=j;k++)
			{
				current_sum+=arr[i];
			}
			max_sum=max(max_sum,current_sum);
		
		}
	}
		cout<<max_sum<<endl;
	return 0;
}
