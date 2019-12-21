#include<iostream>
using namespace std;

int count=0;
int ways(int sr,int sc,int er,int ec,string path)
{
	if(sr==er and sc==ec)
	{ 
		cout<<count<<endl;
		return ;
	}
	if(sr<er) 
	{
	   count=ways(sr++,sc,er,ec);
	}
	if(sc<ec)
	{
		count=count+ways(sr,sc++,er,ec);
	}
}



int main()
{
	cout<<(0,0,2,2);
	return 0;
}
