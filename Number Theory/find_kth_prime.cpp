#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;



vi primes;
bool arr[90000001];

void sieve(){
	
	int maxN=90000000;
	arr[0]=arr[1]=true; 
	
	for(int i=2; i*i<=maxN;i++){
		if(!arr[i]){
			for(int j=i*i;j<=maxN;j+=i){
				arr[j]=true;
			}
		}
	}
	
	for(int i=2;i<=maxN;i++){
		if(!arr[i]){
			primes.push_back(i);
		}
	}
	
	
}
int main(){
	
	int q,n;
	cin>>q;
	sieve();
	
	while(q--){
		cin>>n;
		cout<<primes[n-1]<<endl;
	}
	return 0;
}

/*can also be done as*/

#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void primeSieve(int *p,int n){
	p[0]=p[1]=0;
	p[2]=1;
	
	
	// mark all odd number as prime 
	for(int i=3;i<=n;i+=2){
		p[i]=1;
	} 
	
	//sieve logic to mark non-prime number as zero
	//1.optimisation : iterate only over odd numbers
	for(int i=3;i<=n;i+=2){
		
		if(p[i]){
			// mark all the multiples of that number as not prime
			// 2.optimisation take a jump of 2i from i*i
			for(int j=i*i;j<=n;j+=2*i){
				p[j]=0;
				
			}
		}
	}
    for(int i=0;i<=n;i++){
		if(p[i]){
			v.push_back(i);
		}
	}
	return;
}

int main(){
	
	int N = 1000000;
	int p[N]={0};
	int num;
    cin>>num;
	primeSieve(p,num);
	for(int i=0;i<=num;i++){
		if(p[i]){
			cout<<i<<" ";
		}
	} 
    cout<<endl;
	int k;
    cin>>k;
	cout<<v[k-1];
	return 0;
	
}

