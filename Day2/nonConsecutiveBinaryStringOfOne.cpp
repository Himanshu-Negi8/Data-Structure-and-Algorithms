#include<iostream>
using namespace std;

/*

You have a number given by user uisng that form all binary string in such form so that no binary string conyaining consecutive one's
example for 0 is 0.
		for 1 is the binary is either 0 or 1
		
*/


int nonConsecutiveBinaryStringOfOne(int num)
{
	if(num==0)
	{
		return 1;
	}
	if(num==1)
	{
		return num+1;
		
	}
	return nonConsecutiveBinaryStringOfOne(num-1)+nonConsecutiveBinaryStringOfOne(num-2);
	
}

int main()
{
	cout<<nonConsecutiveBinaryStringOfOne(3)<<endl;
	cout<<nonConsecutiveBinaryStringOfOne(4)<<endl;
	cout<<nonConsecutiveBinaryStringOfOne(5)<<endl;
	return 0;
}
