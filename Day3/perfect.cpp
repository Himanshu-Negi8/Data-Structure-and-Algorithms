#include<iostream>
#include<climits>
using namespace std;

int perfectSquare(int n)
{
	if(n<=0)
	{
		return 0;
	}
	int minValue = INT_MAX;
	int square =1;
	for(int i=1;square<=n;i++)
	{
		minValue = min(minValue,perfectSquare(n-square)+1);
		square=i*i;
	}
	
	return minValue;
}


int main()
{
	cout<<perfectSquare(13)<<endl;
	return 0;
}
