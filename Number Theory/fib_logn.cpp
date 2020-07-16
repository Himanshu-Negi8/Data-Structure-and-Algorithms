#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define REP(i,n) for(int i=1;i<=n;i++) 

using namespace std;

lli arr[3];
lli I[3][3], T[3][3];

void mul(lli a[3][3], lli b[3][3], int dim){
	
	lli res[dim+1][dim+1];
	REP(i,dim){
		REP(j,dim){
			res[i][j]=0;
			REP(k,dim){
				lli x = (a[i][k]*b[k][j])%mod;
//				res[i][j]+=a[i][k]*b[k][j]; 
				res[i][j] = (res[i][j]+x)%mod;
			}
		}
	}
	REP(i,dim) REP(j,dim) a[i][j]=res[i][j];
}


lli getFib(int n){
	if(n<=2) return arr[n];
	
	I[1][1] = I[2][2]=1;
	I[2][1] =I[1][2]=0;
	
	T[1][1]=0;
	T[1][2]=T[2][1]=T[2][2]=1;
	n = n-1;
	
	while(n){
		if(n&1) mul(I,T,2) , n--;
		else mul(T, T, 2) , n/=2;
	}
	lli Fn= (arr[1]*I[1][1]+arr[2]*I[2][1])%mod;
	return Fn; 
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>arr[1]>>arr[2]>>n, n++;
		cout<<getFib(n)<<endl;
	}
	return 0;
}
