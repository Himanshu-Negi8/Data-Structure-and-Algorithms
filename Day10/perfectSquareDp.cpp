#include<iostream>
#include<cstring>
using namespace std;
int perfectSquare(int n,int dp[])
    {
        if(n<=0)
        {
            return 0;
        }
        
       
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int square=1;
        int minValue = INT_MAX;
        for(int i=1;square<=n;i++)
        {
            minValue=min(minValue,perfectSquare(n-square,dp) + 1);
            dp[n]=minValue;
            square=i*i;
        }
        return minValue;
    }

    
int numSquares(int n) {
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return perfectSquare(n,dp);
}

 int numSquaresDp(int n) {
    int dp[n+1];
    int dp[0]=0;
    int dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        int minValue =INT_MAX;
        for(int j=i;j*j<=i;j++)
        {
            int curr_ans = dp[i-j*j]+1;
            minValue = min(minValue,curr_ans);
        }
        dp[i]=minValue;
    }
    return dp[n];
}

    int main()
    {
    	cout<<numSquares(9)<<endl;
    	return 0;
	}
    
    
