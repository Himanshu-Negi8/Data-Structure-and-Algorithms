#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	
	int money = 3,coins=0,coin_five=0,coin_two=0,coin_one=0;
	
	while(money!=0){
		if(money>=5){
			money-=5;
			coins++;
			coin_five++;
		}
		else if(money>=2){
			money-=2;
			coins++;
			coin_two++;
		}
		else{
			money-=1;
			coins++;
			coin_one++;
		}
	}
	cout<<coins<<" "<<coin_five<<" "<<coin_two<<" "<<coin_one<<" ";
	
	return 0;
}
