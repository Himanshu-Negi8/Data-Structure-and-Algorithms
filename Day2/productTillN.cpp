#include<iostream>
using namespace std;

int productTillN(int num)
{
	if(num<=0)
	{
		return 0;
	}
	if(num==1)
	{
		return 1;
	}
	else
	{
		int recursionProduction = productTillN(num-1);
		return num*recursionProduction;
	}
	
}

int main()
{
	int n =10;
	cout<<productTillN(6)<<endl;
	return 0;
}
