#include<iostream>
using namespace std;

int distinctSubsequence(string s1,string s2){
	int dp[s1.length()+1][s2.length()+1];
//	    for(int i=0;i<=s1.length();i++)
//        {
//            lcsStorage[i][0]=0;
//        }
//        for(int j=0;j<=s2.length();j++)
//        {
//            lcsStorage[0][j]=0;
//        }
        for(int row=s1.length();row>=1;row--)
        {
            for(int col=s2.length();col>=1;col--)
            {
                if(s1[row-1]==s2[col-1])
                {
                    dp[row][col]=dp[row-1][col-1]+1;
                    
                }else{
                    dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
                }
            }
        }
        return dp[0][0];
        
}

int main()
{
	cout<<distinctSubsequence("bbaag","bag")<<endl;
	return 0;
}

