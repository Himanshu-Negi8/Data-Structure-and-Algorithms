class Solution {
public:
    int helper(int sr,int sc,int er,int ec,vector<vector<int>>&v){
        if(sr==er and sc==ec){
            return 1;
        }
        
        if(sr>er or sc>ec){
            return 0;
        }
        
        if(v[sr][sc]!=0){
            return v[sr][sc];
        }
        
        int count =0;
        count+=helper(sr,sc+1,er,ec,v);
        count+=helper(sr+1,sc,er,ec,v);
        
        v[sr][sc]=count;
        
        return count;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m+1,vector<int>(n+1));
        return helper(1,1,m,n,v);
    }
};
