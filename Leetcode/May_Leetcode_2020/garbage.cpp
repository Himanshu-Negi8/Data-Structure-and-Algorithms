#include<bits/stdc++.h>
using namespace std;


int main()
{
	
	int a[2][2],b[2][2];
	
	cout<<"MAtrix element for one ::";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	
	cout<<"MAtrix element for two ::";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>b[i][j];
		}
	}
	
	int c[2][2];
	int i,j,k;

	
	for( i=0;i<2;i++){
		for( j=0;j<2;j++){
			c[i][j]=0;
			for(k=0;k<2;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	cout<<"MAtrix multiply is  ::";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
