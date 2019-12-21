#include<iostream>
using namespace std;

bool isPalindrome(string str,int left,int right)
{
	while(left<=right)
	if(str[left]!=str[right])
	{
		return false;	
	}
	left++;
	right--;
}

int palindromePartitioning(string str,int start,int end)
{
	if(start==end)
	{
		return 0;
	}
	if (start>end)
	{
		return 0;
	}
	
	for(int i=0;i<=end;i++)
	{
		int leftCuts = palindromePartitoniing(str,)
	}
}




int main()
{
	return 0;
}
