class Solution {
public:
    int computeDistance(vector<int>v){
        return v[0]*v[0]+v[1]*v[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<int>distance;
        
        
        for(vector<int>p:points){
            distance.push_back(computeDistance(p));
        }
        
        sort(distance.begin(),distance.end());
        
        int distK = distance[K-1];
        
        vector<vector<int>>res(K,vector<int>(2));
        int t=0;
        for(int i=0;i<points.size();i++){
            
            if(computeDistance(points[i])<=distK){
                
                
                res[t++]=points[i];
            }
        }
        return res;
    }
};
