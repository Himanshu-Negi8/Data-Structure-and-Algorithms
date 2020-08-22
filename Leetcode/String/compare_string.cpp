#include<bits/stdc++.h>
using namespace std;


int main(){
	
	
	string a = "pqrsaa abase aaadeda";
	string b = "aaa aa";
	
	char*c = &a[0];
	char*ptr;
	ptr = strtok(c," ");
	
	vector<string>v,p;
	while(ptr!=NULL){
		
		v.push_back(ptr);
		ptr = strtok(NULL," ");
	}

	c = &b[0];
	ptr = strtok(c," ");
	while(ptr!=NULL){
		
		p.push_back(ptr);
		ptr = strtok(NULL," ");
	}
	
	vector<int>ans;
	for(auto a:p){
		string s =a;
		int count=0;
		map<char,int>mp;
		for(char c:a){
			mp[c]++;
		}
		for(auto x:v){
			map<char,int>freq;
			for(char c:x){
				freq[c]++;
			}
			
			sort(x.begin(),x.end());
			sort(s.begin(),s.end());
			if(freq[x[0]]<mp[s[0]]){
				
				count++;
			}
		}
		ans.push_back(count);
	}		
	
	for(auto i:ans){
		cout<<i<<" ";
	}
}
