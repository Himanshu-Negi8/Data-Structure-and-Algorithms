class Solution {
public:
    
    bool searchWord(int i, int j, vector<vector<char>>& board,vector<vector<char>>& visited,int index,string word){
        
        if(index==word.length()){
            return true;
        }
        if(i<0||i>=board.size() ||j<0||j>=board[0].size()||word[index]!=board[i][j]||visited[i][j] ){
            return false;
        }
        
        visited[i][j]=true;
        if(
            searchWord(i+1,j,board,visited,index+1,word)||
            searchWord(i-1,j,board,visited,index+1,word)||
            searchWord(i,j+1,board,visited,index+1,word)||
            searchWord(i,j-1,board,visited,index+1,word)
        )
            return true;
        
        visited[i][j]=false;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        if(r==0){
            return false;
        }
        int c = board[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] && searchWord(i,j,board,visited,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
