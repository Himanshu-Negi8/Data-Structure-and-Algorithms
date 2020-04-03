class Solution {
public:
    int numDistinct(string s, string t) {
        
    long long dp[s.length()+1][t.length()+1];
        
    for(int i=0;i<=t.length();i++){
        dp[s.length()][i] = 0;
    }
        
    for(int j=0;j<=s.length();j++){
        dp[j][t.length()] = 1;
    }
        
    for(int i=s.length()-1;i>=0;i--){
        for(int j=t.length()-1;j>=0;j--){
                
            if(s[i]==t[j]){
                    
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                    
            }else{
                dp[i][j] = dp[i+1][j];
            }
                
        }
    }
        
        
    return dp[0][0];
}
    
};
