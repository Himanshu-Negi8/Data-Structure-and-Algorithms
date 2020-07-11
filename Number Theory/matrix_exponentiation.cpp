#include<bits/stdc++.h>
using namespace std;

#define N 101

#define REP(i,n) for(int i=1;i<=n;i++) 

int arr[N][N],I[N][N];


void mul(int a[][N],int b[][N], int dim){
	int res[dim][dim];
	
	REP(i,dim) {
		REP(j,dim) {
			res[i][j]=0 ;
			REP(k,dim) res[i][j]+=a[i][k]*b[k][j];
		}
	}
	
	REP(i, dim) REP(j,dim) a[i][j]=res[i][j];
}
void power(int a[][N], int dim,int n){
	
	REP(i,dim) REP(j,dim){
		if(i==j) I[i][j]=1;
		else I[i][j]=0;
	}
	//commented lines are naive approach 
//	REP(i, n)
//	mul(I,a,dim);
	
	//below while loop is log n approach like binary exponentiation 
	while(n){
		if(n%2){
			mul(I,a,dim), n--;
		}
		else{
			mul(a,a,dim);
			n/=2; 
		}
	}
	
	REP(i, dim) REP(j,dim) arr[i][j]=I[i][j];
}

void printMat(int a[][N],int dim){
	REP(i,dim){
		REP(j,dim){
			cout<<a[i][j]<<" ";
		} 
		cout<<endl; 
	} 
}
int main(){
	
	int t,dim,n;
	cin>>t;
	while(t--){
		cin>>dim>>n;
		REP(i,dim) REP(j,dim) cin>>arr[i][j];
		
		power(arr,dim,n);
		printMat(arr,dim);
		
	}
	return 0;
}
