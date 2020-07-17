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


int gcd(int a, int b){
	
	return b==0?a:gcd(b,a%b);
}

//nlog(n) approach

int phi(int n){
	int count=0;
	
	for(int i=1;i<=n;i++){
		if(gcd(i,n)==1) count++;
	}
	return count;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		
		cin>>n;
		cout<<phi(n)<<endl;
	}
	return 0;
}
