#include<bits/stdc++.h>
//#include<cstring>
using namespace std;

#define ll long 

ll a[1000005],prefixSum[1000005];
int main(){
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		ll sum=0;
		memset(prefixSum,0,sizeof prefixSum);
		prefixSum[0]=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			sum%=n;
			sum = (sum+n)%n;
			prefixSum[sum]++;
		}
		
		ll ans=0;
		for(int i=0;i<n;i++){
			ll no = prefixSum[i];
			ans+=(no*(no-1))/2;
		}
		cout<<ans;
	}
	return 0;
}
