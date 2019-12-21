#include<iostream>
#include<climits>
using namespace std;

int reducedToOne(int num)
{	int count1=INT_MAX,count2=INT_MAX,count3=INT_MAX;
	if(num%3==0)
	{
		count1 = reducedToOne(num/3)+1;
	}
	if(num%2==0)
	{
		count2 = reducedToOne(num/2)+1;
	}
	count3 = reducedToOne(num-1)+1;
	
	return min(count1,min(count2,count3));
}

int main()
{
	cout<<reducedToOne(10);
	return 0;
}
