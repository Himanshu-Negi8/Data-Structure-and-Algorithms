class Solution {
public:
    int numberOfSteps (int num) {
        if(num<=1){
            return num;
        }
        
        int *dp = new int[num+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        
        for(int i=3;i<=num;i++)
        {
            
            
            if(i%2==0){
                dp[i] = dp[i/2]+1;
            }else{
                dp[i] = dp[i-1]+1;
            }
            
        }
        return dp[num];
    }
};
