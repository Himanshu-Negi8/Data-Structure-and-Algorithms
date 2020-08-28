#include<bits/stdc++.h>
using namespace std;


char spell_of[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void print(int n){
	if(n==0) return;
	
	print(n/10);
	cout<<spell_of[n%10]<<" ";
}

int main(){
	
	
	int n = 2048;
	print(n);
	cout<<endl;
	print(24566);
	
}
