class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size()==2){
            return true;
        }
        int x_diff = coordinates[1][0]-coordinates[0][0];
        int y_diff = coordinates[1][1]-coordinates[0][1];
        
        for(int i=2;i<coordinates.size();i++){
            if((coordinates[i][0]-coordinates[1][0])*y_diff!=(coordinates[i][1]-coordinates[1][1])*x_diff){
                return false;
            }
        }
        return true;
    }
};
