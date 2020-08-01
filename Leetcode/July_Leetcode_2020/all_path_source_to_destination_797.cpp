class Solution {
     map<int,list<int>>adjList;
public:
    void dfs(int node, int dest, vector<vector<int>> &res,vector<int> &v){
        
        if(node==dest){
            v.push_back(node);
            res.push_back(v);
            return;
        }
        v.push_back(node);

        for(auto neighbour:adjList[node]){
            dfs(neighbour,dest,res,v);
            v.pop_back();
           
        }
    }
    
   
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       
        //n is basically the destination
        
        int n = graph.size()-1;
        
        //constructing the graph 
        
        for(int i=0;i<graph.size();i++){
            for(auto j:graph[i]){
                adjList[i].push_back(j);
            }
        }
        
        vector<vector<int>>res;
        vector<int>v;
        dfs(0,n,res,v);
        return res; 
        
        
    }
};
