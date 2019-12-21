#include<iostream>
using namespace std;

int numberOfWays(int num,int k)
{
	if(num<0)
	{
		return 0;
	}
	if(num==0)
	{
		return 1;
	}
	int result=0;
	
	
		for(int i=1;i<=k;i++)
		{
			result+= numberOfWays(num-i,k);
			
		}
		
		return result;
	
}

int main()
{
	cout<<numberOfWays(10,2);//reach to 10th point from 1 and move you can take from 1 to 6 whatever the dice gives
	return 0;
}
