#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        
        
}
int main()
{
//	string s = "himanshu";
//	
//	char * p = new char[s.length()+1];
//	strcpy(p,s.c_str());
//	sort(p,p+s.length());
//	for(int i=0;i<s.length();i++){
//		cout<<p[i]<<" ";
//	}
//	string g(p);
//	cout<<g;
	string s = "pwwkew";
	unordered_map<char,int>mp;
    for(char ch:s){
            mp[ch]++;
	}
	int ans=0;
	for(auto a:mp){
		cout<<a.first<< a.second;
		cout<<endl;
		if(a.second>1){
			ans+=1;
		}else{
			ans+=1;
		}
		
	}
	cout<<ans;
	return 0;
}
