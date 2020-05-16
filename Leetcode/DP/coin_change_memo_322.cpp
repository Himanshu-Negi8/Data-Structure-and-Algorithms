class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
    return helper(coins,amount,dp);
    }
    
    int helper(vector<int> coins,int amount,int dp[])
    {
        if(amount==0){
            return 0;
        }
        
        if(amount<0){
            return -1;
        }
        if(dp[amount]!=0)
        {
            return dp[amount];
        }
        
        int minValue = INT_MAX;
        
        for(int coin:coins)
        {
            int recursionResult = helper(coins,amount-coin,dp);
            
            if(recursionResult>=0){
                minValue=min(minValue,recursionResult+1);
                
            }
        }
        dp[amount]=minValue==INT_MAX?-1:minValue;
        return dp[amount];
    }
};
