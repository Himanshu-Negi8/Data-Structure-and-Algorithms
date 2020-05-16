class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lcsStorage[text1.length()+1][text2.length()+1];
        
        for(int i=0;i<=text1.length();i++)
        {
            lcsStorage[i][0]=0;
        }
        for(int j=0;j<=text2.length();j++)
        {
            lcsStorage[0][j]=0;
        }
        
        for(int row=1;row<=text1.length();row++)
        {
            for(int col=1;col<=text2.length();col++)
            {
                if(text1[row-1]==text2[col-1])
                {
                    lcsStorage[row][col]=lcsStorage[row-1][col-1]+1;
                    
                }else{
                    lcsStorage[row][col]=max(lcsStorage[row-1][col],lcsStorage[row][col-1]);
                }
            }
        }
        return lcsStorage[text1.length()][text2.length()];
    }
};
