class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count=0;
    
        vector<vector<int>>ans(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<ans.size();i++){
            for(int j=1;j<ans[0].size();j++){
                if(matrix[i-1][j-1]==1){
                    ans[i][j] = 1+min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1]));
                    count+=ans[i][j];
                }
                
            }
        }
        return count;
    }
};
