class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
     
        
       
        
        vector<int>v(intervals.size(),-1);
        
        for(int i=0;i<intervals.size();i++){
            int min_diff = INT_MAX;
            for(int j=0;j<intervals.size();j++){
                if(i!=j and intervals[i][1]<=intervals[j][0]){
                    if(v[i]!=-1 and abs(intervals[i][1]-intervals[j][0])<min_diff){
                        v[i]=j;
                    }else if(v[i]==-1){
                        
                        v[i]=j;
                        min_diff=abs(intervals[i][1]-intervals[j][0]);
                    }
                    
                }
            }
        }
        
        return v;
    }
};
