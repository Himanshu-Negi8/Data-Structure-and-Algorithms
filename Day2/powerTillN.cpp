#include<iostream>
using namespace std;

int power(int num,int pow)
{
	if(pow<=0)
	{
		return 1;
	}
	if(pow==1)
	{
		return num*pow;
	}
	else
	{
		int ros = power(num,pow-1);//ros stands for recursionresult
		return num*ros;
	}
	
}

int main()
{
	int n =10;
	cout<<power(3,6)<<endl;
	return 0;
}
