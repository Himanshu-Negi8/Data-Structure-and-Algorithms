#include<iostream>
using namespace std;

int count=0;
void printMazePath(int sr,int sc,int er,int ec,string path)
{
	if(sr==er and sc==ec)
	{ 
		cout<<path<<endl;
		return ;
	}
	if(sr>er and sc>ec) 
	{
		return;
	}
	printMazePath(sr+1,sc,er,ec,path+"V");
	printMazePath(sr+1,sc,er,ec,path+"H");
}



int main()
{
	cout<<printMazePath(0,0,2,2,"")<<endl;
	return 0;
}
