
/*DP - Recusrsion + memoization*/


class Solution {
public:
    bool helper(string s, vector<string>& wordDict, map<string,bool>& mp){
        
        if(s.length()==0) return true;
        else if(mp.find(s)!=mp.end()) return mp[s];
        
        for(auto x:wordDict){
            string prefix = s.substr(0,x.length());
            bool result = false;
            if(prefix ==x){
                mp[s]=true;
                result = helper(s.substr(x.length(),s.length()),wordDict,mp);
            }
            if(result){
                return true;
            }
        }
        mp[s]=false;
        
        return false;
        
            
    }
        
        
        
        
    
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool>mp;
        
        return helper(s,wordDict,mp);
    }
};


/*Recursion*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(s.length()==0) return true;
        
        for(auto x:wordDict){
            string prefix = s.substr(0,x.length());
            bool result = false;
            if(prefix ==x){
                result = wordBreak(s.substr(x.length(),s.length()),wordDict);
            }
            if(result){
                return true;
            }
        }
        
        return false;
    }
};
