class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        reverse(digits.begin(),digits.end());
        
       for(int i=0;i<digits.size();i++){
           int sum = digits[i]+carry;
           digits[i]=sum%10;
           carry = sum/10;
       }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
