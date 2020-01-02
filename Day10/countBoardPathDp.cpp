#include<iostream>
#include<cstring>
using namespace std;

int countBoardPathDp(int start,int end)
{
	int dp[end+1];
	dp[end]=1;
	
	for(int i = end-1;i>=start;i--){

		dp[i] = 0;

		for(int dice = 1;dice<=6;dice++){

			if(i + dice <= end){
				dp[i]+=dp[i+dice];
			}
		}	
	}
}

int countBoardPathMemo(int start,int end,int dp[]){
	if(start==end){
		dp[start] = 1;
		return 1;
	}

	if(start>end){
		return 0;
	}

	if(dp[start]!=0){
		return dp[start];
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPathMemo(start+dice,end,dp);
	}

	dp[start] = count;

	for(int i=0;i<=10;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<"****************"<<endl;

	return count;
}

int main()
{
	int end = 10;
	int dp[end+1];
	memset(dp,0,sizeof(dp));
	cout<<countBoardPathMemo(0,end,dp)<<endl;
	cout<<countBoardPathDp(0,10)<<endl;
	return 0;
}

