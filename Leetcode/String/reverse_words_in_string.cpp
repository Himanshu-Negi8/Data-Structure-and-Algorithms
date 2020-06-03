#include<bits/stdc++.h>
using namespace std;

void change(string &s){
	
	int left=0;
	int right = s.length()-1;
	while(left<=right){
		char ch = s[left];
		s[left]=s[right];
		s[right]=ch;
		left++;
		right--;
	}
}

int main()
{
	string s = 	"world! better we have";

	change(s);
	
	vector<string>nums;
	string word;

	for(int i=0;i<=s.length();i++){
		if(s[i]==' ' || (i==s.length())){
			nums.push_back(word);
		
			word="";
		}else{
			word+=s[i];
		}
	}
	 cout<<endl;
	 string ans;
	for(int i=0;i<nums.size();i++){
		change(nums[i]);
		ans+=nums[i]+' ';
	}
	cout<<ans;
	
	return 0;
}
