#include<iostream>
using namespace std;

bool gotScholarship(long n,long x,long m,long mid,long y)
{
	return mid*x<=m+(n-mid)*y;
}


int studentsGetScholarship(long n,long m,long x,long y)
{
	int start=0;
	int end = n;
	int ans=0;
	
	while(start<=end)
	{
		int mid = start+(end-start)/2;
		
		if(gotScholarship(n,x,m,mid,y))
		{
			ans = mid;
			start=mid+1;
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
	cout<<studentsGetScholarship(5,10,2,1);
	return 0;
}
