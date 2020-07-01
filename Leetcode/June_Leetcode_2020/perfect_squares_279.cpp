class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int minValue =INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                int curr_ans = dp[i-j*j]+1;
                minValue = min(minValue,curr_ans);
            }
            dp[i]=minValue;
        }
        return dp[n];
    }
    
    
};
