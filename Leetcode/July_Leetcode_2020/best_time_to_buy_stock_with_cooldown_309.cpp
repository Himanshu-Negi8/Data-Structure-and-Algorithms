class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        else if(prices.size()<=1) return 0;
        if(prices.size()==2 and prices[0]<prices[1]){
             return prices[1]-prices[0];
        }else if(prices.size()==2 and prices[0]> prices[1]) return 0;
           
        
        vector<vector<int>>v(prices.size(),vector<int>(2,0));
        
        v[0][0]=0;
        v[0][1]=-prices[0];
        
        v[1][0]=max(v[0][0],v[0][1]+prices[1]);
        v[1][1] = max(v[0][1],v[0][0]-prices[1]);
        
        for(int i=2;i<prices.size();i++){
            v[i][0]=max(v[i-1][0],v[i-1][1]+prices[i]);
            v[i][1]=max(v[i-1][1],v[i-2][0]-prices[i]);
        }
        return v[prices.size()-1][0];
    }
};
