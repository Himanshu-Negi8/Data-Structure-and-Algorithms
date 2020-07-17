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

//time complexity logn of binary exponentiation so same goes for this as well
//algorithm of fermatt's 


int power(int a, int n,int m){
	int res=1;
	while(n){
		if(n&1) res = (res*a)%m , n--;
		else a=(a*a)%m, n/=2;
	}
	return res;	
}

int main(){
	
	int t,a,m;
	cin>>t;
	
	while(t--){
		cin>>a>>m;
		cout<<"a^-1 is : "<<power(a, m-2, m)<<endl;
	}
	 
	return 0;
}
