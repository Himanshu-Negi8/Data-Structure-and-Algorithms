#include<iostream>
using namespace std;

bool cowsPlaced(int stalls[],int n,int c,int min_sep){

	//Place the first cow in first stall
	int last_cow = stalls[0] ;
	int cnt = 1;

	//Go over remaining stalls,try to place c-1 cows
	for(int i=1;i<n;i++){
		if(stalls[i] - last_cow>=min_sep){
			last_cow = stalls[i];
			cnt++;

			if(cnt==c){
				return true;
			}
		}
	}
	return false;

}
int cowsProblem(int arr[],int n,int cows)
{
	int start =0;
	int end = arr[n-1]-arr[0];
	int ans =0;
	
	while(start<=end)
	{
		int mid = (start+end)/2;
		
		bool cowCanPlace = cowsPlaced(arr,n,cows,mid);
		
		if(cowCanPlace)
		{
			ans =mid;
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
	
	int arr[5] = {1,2,4,8,9};
	
	int n=5;
	cout<<cowsProblem(arr,n,3);
	return 0;
}
