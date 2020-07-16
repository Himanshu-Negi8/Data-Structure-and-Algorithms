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


lli power(lli a, lli n, lli d){
	
	lli res=1;
	
	while(n){
		if(n&1) res=((res%d)*(a%d))%d , n--;
		else a=( (a%d) * (a%d) )%d, n/=2;
	}
	return res;
}


lli gcd(lli a, lli b, lli n){
	
	if(a==b){
		return (power(a, n ,mod)+power(b, n, mod))%mod; 
	}
	
	lli candidate =1;
	lli num = a-b;
	
	
	for(lli i=1; i*i<=num;i++)
		if(num%i==0){
			lli temp = (power(a,n,i)+power(b,n,i))%i;
			
			if(temp==0) candidate=max(candidate,i);
			
			temp= (power(a,n,num/i)+power(b,n,num/i))%(num/i);
			
			if(temp==0) candidate=max(candidate,num/i);
		}
	return candidate%mod;
}




int main(){
	lli a,b,n,t;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		cout<<gcd(a,b,n)<<endl;
	}
	return 0;
}
