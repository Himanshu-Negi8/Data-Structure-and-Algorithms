class Solution {
public:
    int minDistance(string word1, string word2) {
       /*if first string is empty then we have
       to perform insertion upto second string length*/
        
        if(word1.length()==0){
            return word2.length();
        }
        
        /*same goes to this case if seecond string is 
        empty then we have to remove all characters
        from first string that is legth of first string*/
        
        if(word2.length()==0){
            return word1.length();
        }
        
        //defining the dp array 
        
        int dp[word1.length()+1][word2.length()+1];
        
        //initializing the total no of operations required to form empty string to second string
        
        for(int i=0;i<=word2.length();i++){
            dp[0][i]=i;
        }
        //initializing the total number of operations to form empty stirng to first string 
        
        for(int i=0;i<=word1.length();i++){
            dp[i][0]=i;
        }
        
        
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                //if characters are not similar than taking min of left,top and diagonal and increase by 1
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }else{
                    dp[i][j]=dp[i-1][j-1]; //simply copy the diagonal if characters are same
                }
            }
        }
        
        return dp[word1.length()][word2.length()];
    }
};
