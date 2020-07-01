class Solution {
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            mp[ticket[0]].push(ticket[1]);
        }
        
        dfs("JFK");
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    void dfs(string src) {
        while (!mp[src].empty()) {
            string dst = mp[src].top();
            mp[src].pop();
            
            dfs(dst);
        }
        
        ans.push_back(src);
    }
};
