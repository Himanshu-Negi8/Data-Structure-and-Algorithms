#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;



int medianOfMatrix(int arr[3][3],int row,int col)
{
	int maxRange=INT_MIN;
	int minRange = INT_MAX; 
	
	for(int i=0;i<row;i++)
	{
		maxRange = max(maxRange,arr[i][col-1]);
		minRange = min(minRange,arr[i][col-2]);
	}
	int check = (row*col)/2+1;
	while(minRange<maxRange)
	{
		int mid = minRange+(maxRange-minRange)/2;
		int count=0;
		for(int i=0;i<row;i++)
		{
			count+=upper_bound(arr[i],arr[i]+col,mid)-arr[i];
		}
		if(count<check)
		{
			minRange = mid+1;
		}
		else{
			maxRange = mid;
		}
	}
	return maxRange;
}

int main()
{
	int arr[3][3] = {{2,6,8},{3,6,8},{1,3,5}};
	cout<<medianOfMatrix(arr,3,3)<<endl;
	return 0;
}
