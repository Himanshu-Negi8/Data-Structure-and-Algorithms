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

int F[1000001];


int power(int a, int n){
	int res=1;
	while(n){
		if(n&1) res = (res*1LL*a)%mod , n--;
		else a=(a*1LL*a)%mod, n/=2;
	}
	return res;	
}

int C(int n , int k){
	
	if(k>n){
		return 0;
	}
	
	int result = F[n];
	result = result*1LL*power(F[k], mod-2)%mod;
	result = result*1LL*power(F[n-k],mod-2)%mod;
	
	return result;
}


int main(){
	F[0]=F[1]=1;
	for(int i=2;i<=1000000;i++){
		F[i] = (F[i-1]*1LL*i)%mod;
	}
	
	int q;
	int n,k;
	
	cin>>q;
	
	while(q--){
		cin>>n>>k;
		cout<<C(n,k)<<endl;
	}
	return 0;
}
