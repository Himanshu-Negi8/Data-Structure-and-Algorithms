class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len =s1.length();
        
        if(len>s2.length()){
            return false;
        }
        
        unordered_map<char,int>first,window;
        
        for(int i=0;i<len;i++){
            first[s1[i]]++;
        }
        
        for(int i=0;i<s2.length();i++){
            
            window[s2[i]]++;
            
            if(i>=len){
                window[s2[i-len]]-=1;
                
            }
            if(window==first){
                return true;
            }
        }
        return false;
        
    }
};
