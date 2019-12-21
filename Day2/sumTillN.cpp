#include<iostream>
using namespace std;

int sumTillN(int num)
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
		int recursionSum = sumTillN(num-1);
		return num+recursionSum;
	}
	
}

int main()
{
	int n =10;
	cout<<sumTillN(10)<<endl;
	return 0;
}
