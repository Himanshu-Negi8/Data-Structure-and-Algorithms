#include<iostream>
#include<cstring>
using namespace std;


int longestIncreasingSubsequence(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		return 0;
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	if(ch1==ch2){

		return 1 + longestIncreasingSubsequence(ros1,ros2);

	}else{

		int firstChoice = longestIncreasingSubsequence(s1,ros2);
		int secondChoice = longestIncreasingSubsequence(ros1,s2);

		return max(firstChoice,secondChoice);
	}
}
const int MAX = 100;

int dp[MAX][MAX];

int lcsMemo(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		dp[s1.length()][s2.length()] = 0;
		return 0;
	}

	if(dp[s1.length()][s2.length()]!=-1){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	int result;

	if(ch1==ch2){

		result  = 1 + lcsMemo(ros1,ros2);

	}else{

		int firstChoice = lcsMemo(s1,ros2);
		int secondChoice = lcsMemo(ros1,s2);

		result =  max(firstChoice,secondChoice);
	}

	dp[s1.length()][s2.length()] = result;

	return result;
}

int longestCommonSubsequenceDP(string text1, string text2) {
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

int main()
{
	memset(dp,-1,sizeof(dp));
	cout<<lcsMemo("abcde","ade");
	return 0;
}
