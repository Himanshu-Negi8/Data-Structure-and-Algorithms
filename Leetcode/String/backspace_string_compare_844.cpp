class Solution {
    
    
public:
    string removes(string s){
        
        string p;
        for(char ch:s){
            if(ch=='#'){
                if(!p.empty()){
                    p.pop_back();
                }
            }else{
                p+=ch;
            }
        }
        return p;
    }
    bool backspaceCompare(string S, string T) {
        
          return removes(S)==removes(T);
              
    }
};
