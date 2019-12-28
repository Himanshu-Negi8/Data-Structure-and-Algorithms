#include<iostream>
using namespace std;

void printSubsequence(string str,string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}
	
	char ch = str[0];
	string ros = str.substr(1);
	
	
	printSubsequence(ros,ans);
	printSubsequence(ros,ans+ch);
	
}

int main()
{
	string s = "ab";
	printSubsequence(s,"");
	return 0;
}



