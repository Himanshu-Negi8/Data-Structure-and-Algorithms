class Solution {
public:
    bool isPalindrome(string s) {
        
        
        string p;

        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i])||isalpha(s[i]))
            {
                p+=tolower(s[i]);
            }
        } 
        
        int left=0;
        int right =p.length()-1;
        
        while(left<=right)
        {
            if(p[left]!=p[right])
            {
                return false;
            }
            left++;right--;
        }
        
        return true;
        
    }
};
