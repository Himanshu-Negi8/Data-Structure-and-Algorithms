/*

For Problem Description Refer -leetcode 1431
1431. Kids With the Greatest Number of Candies
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int largest = *max_element(candies.begin(),candies.end());
        vector<bool>res(candies.size());
        
        for(int i=0;i<candies.size();i++){
            candies[i]+=extraCandies;
        }
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]>=largest){
                res[i]=true;
            }else{
                res[i]=false;
            }
        }
        return res;
    }
};
