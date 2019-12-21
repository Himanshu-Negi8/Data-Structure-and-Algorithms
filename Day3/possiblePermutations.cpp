#include<iostream>
using namespace std;

void possiblePermutation(string str1,string str2,string ans)
{
	if(str1.length()==0)
	{
		cout<<ans<<endl;
	}

	for(int i=0;i<str1.length();i++)
	{
		char ch = str1[i];
		for(int j=0;j<str2.length();j++)
		{
		string ros = str1.substr(0,i)+str2.substr(0,j);
		possiblePermutation(ros,str2,ans+ch+ros);
		}
	
		
		
	}
}


int main()
{
	string s1 ="abc";
	string s2="def";
	possiblePermutation(s1,s2,"");
	return 0;
}
