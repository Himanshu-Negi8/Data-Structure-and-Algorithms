class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i = a.length()-1;
        int j = b.length()-1;
        
        int carry=0;
        while(i>=0||j>=0){
            
            int sum = carry;
            if(i>=0) sum+=a[i]-'0';
            if(j>=0) sum+=b[j]-'0';
            s+=to_string(sum%2);
            carry = sum/2;
            
            i--;
            j--;
        }
        if(carry!=0){
            s+=to_string(carry);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
