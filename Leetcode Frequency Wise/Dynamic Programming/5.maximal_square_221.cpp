class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int rows = matrix.size();
        int cols= rows>0?matrix[0].size():0;
        
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
        
        int max_len = 0;
        
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    max_len = max(max_len,dp[i][j]);
                }
            }
        }

        return max_len*max_len;
    }
};
