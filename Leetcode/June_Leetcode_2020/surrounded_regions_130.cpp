class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(board[i][j]=='X' || board[i][j]=='*')
            return;
        board[i][j]='*';
         dfs(board,i+1,j,n,m);
         dfs(board,i-1,j,n,m);
         dfs(board,i,j+1,n,m);
         dfs(board,i,j-1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        if(n==0)
            return;
        int m= board[0].size();
        int i,j;
        
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
              
                if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
                  dfs(board,i,j,n,m); 
            }
        
        for(i=0;i<n;i++)
         for(j=0;j<m;j++)
         { if(board[i][j]=='*')
                    board[i][j]='O';
                else
                    board[i][j]='X';
         }
        
    }
};
