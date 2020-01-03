#include<iostream>
using namespace std;

int knapsack(int values[],int capacity[],int N,int weight)
{
	
	if(weight==0||N==0)
	{
		return 0;
	}
	
	int taken=0,leave=0;
	if(capacity[N-1]<=weight)
	{
		 taken =values[N-1]+knapsack(values,capacity,N-1,weight-capacity[N-1]);
	}
	
	leave= 0+knapsack(values,capacity,N-1,weight);
	
	return max(taken,leave);
}

int knapSackMemo(int values[],int capacity[],int N,int max_capacity)
{
	return 0;
}


int main()
{
	int values[]={50,20,60,30};
	int capacity[]={5,3,8,3};
	int n=4;
	cout<<knapsack(values,capacity,n,8)<<endl;;
	return 0;
}
