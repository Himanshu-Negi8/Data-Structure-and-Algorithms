class Solution {
public:
    int addDigits(int num) {
        if(num==0 || num==1){
            return num;
        }
        
        int res=0;
        int f=0;
        while(num>0 || res>0){
            if(num!=0){
                int rem = num%10;
                res+=rem;
                num/=10;
            }
            else{
                
                int rem = res%10;
                f+=rem;
                res/=10;
            }
            
        }
        if(f%10==0){
            return 1;
        }
        return f;
    }
};

//
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
