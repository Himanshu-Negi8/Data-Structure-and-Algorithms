class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0 && t.length()!=0){
            return true;
        }
        
        int n = s.length();
        int m = t.length();
        
        int i=0,j=0;
        
        while(i<n&&j<m){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==n;
        
    }
};
