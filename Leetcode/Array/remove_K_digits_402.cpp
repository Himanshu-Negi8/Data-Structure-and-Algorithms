class Solution {
public:
    string removeKdigits(string num, int k) {
        // Idea is to use a stack, the number is inserted
        // when it is bigger than the stack top
        string s;
        for(int i = 0; i < num.size(); i++) {
            while(!s.empty() && s.back() > num[i] && k) 
                s.pop_back(), --k;
            s += num[i];
        }
        // when digits are in non-decreasing order, remove k from last
        while(!s.empty() && k)
            s.pop_back(), --k;
        // remove leading zeros
        int i = 0;
        while(i < s.size() && s[i] == '0')
            ++i;           
        
        // if the string is empty after removing zeros, then return 0, else the remaining string
        return i == s.size() ? "0" : s.substr(i);
    }
};
