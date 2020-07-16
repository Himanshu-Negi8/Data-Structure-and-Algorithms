#include<bits/stdc++.h>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int>v(2,0);
	
	for(int i=0;i<a.size();i++){
		
		
		if(a[i]>b[i]){
			v[0]++;
		}
		else if(a[i]<b[i]){
			v[1]++;
		}else{
			continue;
		}
	}
    return v;
}

int main(){
	vector<int>a(3),b(3);
	a[0]=5,a[1]=6;a[2]=7;
	b[0]=3,b[1]=6;b[2]=10;
	
	vector<int>v(2,0);
	v= compareTriplets(a,b);
	for(int i:v){
		cout<<i<<endl;
	}
	return 0;
}
