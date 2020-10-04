//binary search approach for each row	

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row=0;
        
     
        while(row<rows){
		int i=0;
		int j=cols-1;
		while(i<=j){
			int mid = (i+j)/2;
			if(matrix[row][mid]==target){
				return true;
			}else if(matrix[row][mid]<target){
				i=mid+1;
			}else{
				j=mid-1;
			}
		}
		row++;
	}
        
        
	return false;
    }
};


//stair-case approach 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i =0,j=c-1;
        int start = matrix[i][j];
	    if(start==target) return true;
        
        while(j>=0 and i<r){

            if(start<target){
                i++;
                if(i<r){
                    if(matrix[i][j]==target) {
                        return true;
                    } 
                    else start=matrix[i][j];
                }
                
            }
            if(start>target){
                j--;
                if(j>=0){
                    if(matrix[i][j]==target) {
                    return true;
                }
                else start=matrix[i][j];
                }
                
            }
        }
        
	    return false;
    }
};
