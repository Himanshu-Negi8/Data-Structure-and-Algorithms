
class Solution {
public:
    bool checkValidString(string s) {
        
        int length = s.length() - 1;
        int openCount = 0, closedCount = 0;
        for (int i = 0; i <= length; i++)
        {
            if (s[i] == '*' || s[i] == '(') openCount++;
            else openCount--;
            if (s[length - i] == '*' || s[length - i] == ')') closedCount++;
            else closedCount--;
            if (openCount < 0 || closedCount < 0) return false;
        }
        return true;
       
    }
};
