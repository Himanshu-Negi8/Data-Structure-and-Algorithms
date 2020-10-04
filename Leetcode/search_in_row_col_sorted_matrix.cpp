#include<bits/stdc++.h>
using namespace std;





//binary search code O(nlogn) complexity

int rows,cols;
	cin>>rows>>cols;
	
	int **arr = new int*[rows];
	for(int i=0;i<rows;i++){
		arr[i] = new int[cols];
	}
	
	cout<<"fill array elements : ";
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<endl;
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<setw(3)<<arr[i][j];
		}
		cout<<endl;
	}
	
	
	
	cout<<"item to be searched : "<<" ";
	
	int item;
	cin>>item;
	
	int row=0;

	bool flag=false;
	while(row<rows){
		
		int i=0;
		int j=cols-1;
		while(i<=j){
			int mid = (i+j)/2;
			if(arr[row][mid]==item){
				flag=true;
				cout<<row<<" "<<j<<endl;
				break;
			}else if(arr[row][mid]<item){
				i=mid+1;
			}else{
				j=mid-1;
			}
		}
		if(flag) break;
		else row++;
	}
	





//stair case search algo implementation O(rows+cols) complexity

int main(){
	int r,c;
	cin>>r>>c;
	
	int **arr = new int*[r];
	for(int i=0;i<r;i++){
		arr[i] = new int[c];
	}
	
	cout<<"fill array elements : ";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<endl;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<setw(3)<<arr[i][j];
		}
		cout<<endl;
	}
	
	
	
	cout<<"item to be searched : "<<" ";
	
	int item;
	cin>>item;
	int i=0,j=c-1;
	int start = arr[i][j];
	
	while(i<r and j>=0){
		
		if(start<item){
			i++;
			if(arr[i][j]==item) {
				cout<<i<<" "<<j;
				break;
			} 
			else start=arr[i][j];
		}
		else if(start>item){
			j--;
			if(arr[i][j]==item) {
				cout<<i<<" "<<j;
				 break;
			}
			else start=arr[i][j];
		}
	}
	
	
	return 0;
}
