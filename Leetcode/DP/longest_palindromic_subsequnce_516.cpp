class Solution {
public:
    int longestPalindromeSubseq(string s) {
       
        
    int n = s.length();
        
    int dp[n][n];
        
    memset(dp,0,sizeof(dp));
        
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
        
    for(int col=1;col<n;col++){
        for(int row=col-1;row>=0;row--){
                
            if(s[row]==s[col]){
                dp[row][col] = dp[row+1][col-1] + 2;
            }else{
                dp[row][col] = max(dp[row][col-1],dp[row+1][col]);
            }
        }
    }
        
    return dp[0][n-1];   
}

};
