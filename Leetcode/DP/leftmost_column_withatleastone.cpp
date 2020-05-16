/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dimension = binaryMatrix.dimensions();
        int rows=dimension[0];
        int columns = dimension[1];
        
        int current_row=0;
        int current_col = columns-1;
        
        while(current_row<rows && current_col>=0)
        {
            if(binaryMatrix.get(current_row,current_col)==0)
            {
                
                current_row+=1;
            }else{
                current_col-=1;
            }
        }
        
        if(current_col!=columns-1){
            return current_col+1;
        }else{
            return -1;   
        }
        
    }
};
