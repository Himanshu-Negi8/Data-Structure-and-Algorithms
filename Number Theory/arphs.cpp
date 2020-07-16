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


lli power(lli a, lli n, lli p){
	lli res=1;
	
	while(n){
		if(n&1) res=(res*a)%p , n--;
		else a = (a*a)%p , n/=2;
	}
	return res;
}

int main(){
	
	int n;
	cin>>n;
	cout<<power(8,n,10);
	
	
	return 0;
}
