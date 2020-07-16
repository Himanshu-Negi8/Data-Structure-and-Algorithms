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

int pre[100005],suff[100005];
int arr[100001];


int gcd(int a,int b){
	
	return b==0?a:gcd(b,a%b);
}


int main(){
	int t,n,q,l,r;
	cin>>t;
	while(t--){
		
		cin>>n>>q;
		
		pre[0]=suff[n+1]=0;
		
		REP(i,n) cin>>arr[i] , pre[i]=gcd(arr[i],pre[i-1]);
		
		for(int i=n;i>=1;i--){
			suff[i]=gcd(arr[i],suff[i+1]);
		}
		
		while(q--){
			cin>>l>>r;
			cout<<gcd(pre[l-1],suff[r+1])<<endl;
		}
	}
	return 0;
}
