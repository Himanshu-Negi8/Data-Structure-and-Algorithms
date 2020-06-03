class Solution {
public:
int findJudge(int N, vector<vector<int>>& trust) {
            if(trust.size()==0){ 
                return 1; 
            }

    map<int,int>P,R;
   
    for(int i=0;i<trust.size();++i)
    {
       P[trust[i][0]]++;          //for finding is there anyone who don't trust anyone
        
        R[trust[i][1]]++;        //counting how many elements trust judge
    }
    
    for(int i=1;i<=N;++i)
    {
       if(P[i]==0&&R[i]==N-1)      //checking if there is any element that trust nobody
        {                                    //and everyone trust him except he himself
           return i;
        }
    }
    return -1;                       //if there is no one then returning -1    
}
};
