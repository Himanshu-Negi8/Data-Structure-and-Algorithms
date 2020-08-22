#include<bits/stdc++.h>
using namespace std;


int main(){
	
	string s = "abppprrr";
	stack<char>st;
	
	int x=5,y=4;
	int count1=0,count2=0;
	for(int i=0;i<s.length();i++){
		
		if(st.empty()) st.push(s[i]);
		
		else if(!st.empty() and (s[i]=='r' and st.top()=='p')){
			st.pop();
			count1++;
		}
		else if(!st.empty() and (s[i]=='p' and st.top()=='r')){
			st.pop();
			count2++;
		}
		
		else{
			st.push(s[i]);
		}
	}
	
	
	
	while(!st.empty()) st.pop();
	
	int ans1 = count1*x+count2*y;
	
	count1=0,count2=0;
	reverse(s.begin(),s.end());
	
	for(int i=0;i<s.length();i++){
		if(st.empty()) st.push(s[i]);
		
		else if(!st.empty() and (s[i]=='p' and st.top()=='r')){
			st.pop();
			count2++;
		}
		else if(!st.empty() and (s[i]=='r' and st.top()=='p')){
			st.pop();
			count1++;
		}
		
		else{
			st.push(s[i]);
		}
	}
	
	while(!st.empty()) st.pop();
	int ans2 = count1*x+count2*y;
	
	int ans = max(ans1,ans2);

	cout<<ans;
	
	
	return 0;
}
