#include<iostream>
using namespace std;

int count=0;
//void printMazePath(int sr,int sc,int er,int ec,string path)
//{
//	if(sr==er and sc==ec)
//	{ 
//		cout<<path<<endl;
//		return ;
//	}
//	if(sr>er and sc>ec) 
//	{
//		return;
//	}
//	printMazePath(sr+1,sc,er,ec,path+"V");
//	printMazePath(sr,sc+1,er,ec,path+"H");
//}
void printMazePath(int sr,int sc,int er,int ec,string path){
	if(sr==er and sc==ec){
		cout<<path<<endl;
		return;
	}

	if(sr>er or sc>ec){
		return;
	}

	printMazePath(sr+1,sc,er,ec,path + "V");
	printMazePath(sr,sc+1,er,ec,path + "H");
}

int countWays(int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec)
	{
		return 1;
	}
	if(sr>er and sc>ec)
	{
		return 0;
	}
	int count=0;
	int vertical =countWays(sr+1,sc,er,ec);
	int horizontal = countWays(sr,sc+1,er,ec);
	count =horizontal+vertical;
	return count;
}
int main()
{
	printMazePath(0,0,2,2,"");
	cout<<countWays(0,0,2,2);
	return 0;
}
