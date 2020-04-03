


class Solution {
public:
    
   int numSquareSum(int n) 
{ 
    int squareSum = 0; 
    while (n) 
    { 
        squareSum += (n % 10) * (n % 10); 
        n /= 10; 
    } 
    return squareSum; 
} 
  
    bool isHappy(int n) {
        set<int> st; 
        while (1) 
        { 
            n = numSquareSum(n); 
            if (n == 1) 
                return true; 
            if (st.find(n) != st.end()) 
                return false; 
            st.insert(n); 
        } 
    }
};
