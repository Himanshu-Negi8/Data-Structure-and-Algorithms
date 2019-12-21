#include<iostream>
using namespace std;


int countBoardPath(int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec)
	{
		return 1;
	}
	
	if(sr>er or sc>ec)
	{
		return 0;
	}
	
	int horizontal = countBoardPath(sr,sc+1,er,ec);
	int vertical = countBoardPath(sr+1,sc,er,ec);
	return horizontal+vertical;
}


int main()
{
	
	cout<<countBoardPath(0,0,2,2)<<endl;
	return 0;
}
