 #include<iostream>
using namespace std;

string moveAllXToEnd(string str)
{
	if(str.length()==0)
	{
		return "";
	}
	char ch =str[0];
	string ros = str.substr(1);
	string result = moveAllXToEnd(ros);
	if(ch=='x')
	{
		return result+ch;
	}
	else
	{
		return ch+result;
	}
	
	
	
}

int main()
{
	string s = "xxxxaxxbc";
	cout<<moveAllXToEnd(s);
	return 0;
}



