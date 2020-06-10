/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

"Samarth"->samarth
*/

class Solution {
public:
    string toLowerCase(string str) {
        
        if(str.length()==0){
            return str;
        }
        
        for(int i=0;i<str.length();i++){
            if(str[i]<=90 && str[i]>=65){
                str[i]=str[i]+32;
            }
        }
        return str;
    }
};
