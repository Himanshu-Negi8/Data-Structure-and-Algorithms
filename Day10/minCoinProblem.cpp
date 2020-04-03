#include<iostream>
using namespace std;


int minCoins(int coins[],int n,int amount)
{
    if(amount==0){
        return 0;
    }
    
    if(amount<0){
        return -1;
    }
    
    int minValue = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        int recursionResult = minCoins(coins,n,amount-coins[i]);
        
        if(recursionResult>=0){
            minValue=min(minValue,recursionResult+1);
        }
    }
    return minValue==INT_MAX?-1:minValue;
}


int minCoinsDp(int coins[],int amount,int n)
{
	int dp[amount+1];
        for(int i=0;i<=amount;i++) dp[i]=amount+1;
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(i-coin>=0){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount] > amount ? -1:dp[amount];
}
int main()
{
	int coins[]={1,2,5};
	int n=3;
	int amount=17;
	cout<<minCoinsDp(coins,amount,n);
	return 0;
}
