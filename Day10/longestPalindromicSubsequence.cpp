#include<iostream>
using namespace std;


int longestPalindromicSubsequence(string s,int left,int right)
{
    if(left>right)
    {
        return 0;
    }
    if(left==right)
    {
        return 1;
    }
    
    char ch1 = s[left];
    char ch2 = s[right];
    int result =0;
    if(ch1==ch2)
    {
        result = longestPalindromicSubsequence(s,left+1,right-1)+2;
    }else{
        int first = longestPalindromicSubsequence(s,left+1,right);
        int second = longestPalindromicSubsequence(s,left,right-1);
        result = max(first,second);
    }
    return result;
}


int longestPalindromicSubsequenceDP(string s)
{
	int n = s.length()
	int dp[n][n];
	
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
	}

}

int main()
{
	string s="bbab";
	cout<<longestPalindromicSubsequence(s,0,s.length());
	return 0;
}
