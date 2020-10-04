#include<bits/stdc++.h>
using namespace std;


int main(){
	
	
	vector<int>gas{ 2,3,4};
	vector<int>cost{3,4,3};
	
	int n = gas.size();
	bool flag;
	int j;
	for(int i=0;i<2*n;i++){
		
		int tc = gas[i%n]-cost[i%n];
		if(tc<0){
			
			flag=false;
		}else{
			flag=true;
			j=i%n;
		}
	}
	
	if(flag) cout<<"True"<<" "<<j;
	
	return 0;
}
