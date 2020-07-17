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
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}


int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		
	
		cin>>a>>b;
	
		if(gcd(a,b)==1){
			cout<<"True"<<endl;
		}
		else{
			cout<<"False"<<endl;
		}
		
	}
	return 0;
}
