class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0){
            return {0};
        }
        else if(num==1){
            return {0,1};
        }
        vector<int>res;
        res.push_back(0);
        for(int i=1;i<=num;i++){
            
            int count=__builtin_popcount(i);
            res.push_back(count);
        }
        return res;
    }
};
