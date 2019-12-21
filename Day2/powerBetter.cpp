#include<iostream>
using namespace std;


int powerBetter(int num,int p)
{
	if(p<=0){
		return 1;
	}
	
	int power = powerBetter(num,p/2);
	int powerSquare = power*power;
	
	return p&1 ? powerSquare*num : powerSquare;
	
}




int main()
{
	cout<<powerBetter(2,4)<<endl;
	return 0;
}
