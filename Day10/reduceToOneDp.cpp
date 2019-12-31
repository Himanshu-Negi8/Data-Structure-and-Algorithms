#include<iostream>
using namespace std;

int reduceToOneDp(int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		int count1=INT_MAX,count2=INT_MAX,count3=INT_MAX;
		if(i%3==0)
		{
			count3 = dp[i/3]+1;	
		}
		if(i%2==0)
		{
			count2 = dp[i/2]+1;
		}
		count1 = dp[i-1]+1;
		dp[i]=min(count1,min(count2,count3));
	}
	
	return dp[n];
}
int main()
{
	int n;
	int dp[n+1];
	cout<<reduceToOneDp(5);
	return 0;
}
