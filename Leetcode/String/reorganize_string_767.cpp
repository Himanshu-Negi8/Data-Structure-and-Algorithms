class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int>mp;
        
        string res;
        
        for(auto c:S){
            mp[c]++;
        }
        
        
        priority_queue<pair<int,char>>pq;
        
        for(auto p:mp){
            pq.push({p.second,p.first});
        }
        
        
        while(pq.size()){
            
            auto[freq1,ch1] = pq.top();pq.pop();
            res.push_back(ch1);
            
            if(pq.empty()){
                if(freq1>1) return "";
                else break;
            }
            
            auto[freq2,ch2] = pq.top();pq.pop();
            res.push_back(ch2);
            
            if(--freq1) pq.push({freq1,ch1});
            if(--freq2) pq.push({freq2,ch2});
        }
        
        return res;
        
    }
};
