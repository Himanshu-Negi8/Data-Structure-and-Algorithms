#include<bits/stdc++.h>
using namespace std;



int main(){
	
	string str = "Hello, world this is nothing";
	
	char*ptr;
	ptr = strtok(str,",");
	
	while(ptr!=NULL){
		cout<<ptr<<endl;
		ptr = strtok(NULL,",");
	}



	return 0;
}
