class Solution {
public:
    int distance(int x,int y){
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<points.size();i++){
            pq.push(make_pair(distance(points[i][0],points[i][1]),i));
        
        }
        vector<vector<int>>v;
    
        while(K){
            
            v.push_back(points[pq.top().second]);
            pq.pop();
            K--;
        }
        return v;
    }
};
