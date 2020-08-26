#include<iostream>
using namespace std;


void printPermutations(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++){
		char ch = str[i];

		string ros = str.substr(0,i) + str.substr(i+1);
		printPermutations(ros,ans+ch);
	}
}


int main()
{
	string s1 ="abc";
	
	printPermutations(s1,"");
	return 0;
}
