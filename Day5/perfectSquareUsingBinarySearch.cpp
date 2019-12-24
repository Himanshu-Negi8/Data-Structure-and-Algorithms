#include<iostream>
using namespace std;

int perfectSquare(int num)
{
	int start =0;
	int end = num;
	int ans=0;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(mid*mid==num)
		{
			ans =mid;
			return ans;
		}
		else if(mid*mid<num)
		{
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	
	return ans; 
}

int main()
{
	cout<<perfectSquare(17);
	
	return 0;
}
