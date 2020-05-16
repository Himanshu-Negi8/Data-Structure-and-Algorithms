#include<bits/stdc++.h>
using namespace std;



int main()
{
	vector<int>v;
	
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	sort(v.begin(),v.end());
	unordered_map<int,int>mp;
	
	for(int a:v){
		mp[a]++;
	}
	
//	for(auto a:mp){
//		cout<<a.first<<"  " <<a.second<<endl;
//	}

	vector<int>p;
	for(int i=0;i<=v.size();i++){
            if(mp.count(v[i])){
            	cout<<v[i]<<"   ";
                continue;
            }else{
                p.push_back(i);
            }
        }
        
        for(int a:p){
        	cout<<a<<endl;
		}
	return 0;
}
