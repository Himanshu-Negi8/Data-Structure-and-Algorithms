class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end() and mp[t[i]]!=0){
                mp[t[i]]--;
            }
                
        }
        
        int count=0;
        for(auto a:mp){
            count+=a.second;
        }
        
        return count;
    }
};
