//not space efficient
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>v(rows,vector<int>(cols));
        int idx=0;
        for(int i=rows-1;i>=0;i--){
        
            for(int j=0;j<cols;j++){
                v[idx][j]=matrix[i][j];
            }
            idx++;
        }
        idx=0;
        
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                matrix[j][i]=v[idx][j];
            }
            idx++;
        }
        
        
    }
};

//efficent approach without space
class Solution {
public:
    void reverse(vector<int>& row){
        int i = 0;
        int j = row.size()-1;
         while(i<j){
            swap(row[i],row[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<vector<int>>& mat) {
        // create transpose of matrix
        for(int i = 0; i<mat.size(); i++){
            for(int j = i; j < mat[i].size(); j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        // swap each elements from start and end of row in matrix
      for(int i = 0; i<mat.size(); i++){
          reverse(mat[i]);
      }
       
        
    }
};
