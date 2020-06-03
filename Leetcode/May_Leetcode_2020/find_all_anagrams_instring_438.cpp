class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char,int> map;
        int start=0;
        int matched = 0;
        for(auto x : p){
            map[x]++;
        }
        
        for(int end =0 ; end<s.size(); end++){
            char right  = s[end];
            if(map.find(right)!=map.end()){
                map[right]--;
                if(map[right]==0){
                    matched++;
                }
            }
            if(matched==map.size())
            {
                res.push_back(start);
            }
            if(end>=p.size()-1){
                char left = s[start++];
                if(map.find(left)!=map.end()){
                    if(map[left]==0){
                        matched--;
                    }
                    map[left]++;
                }
            }
            
        }
        return res;
    }
};
