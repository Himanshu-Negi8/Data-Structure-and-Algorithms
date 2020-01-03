#include<iostream>
using namespace std;

int distinctDP[6][4];

int helper(string s,int si,string t,int ti){
    if(ti==t.length()){
    	distinctDP[si][ti] = 1;
        return 1;
    }
        
    if(si==s.length()){
    	distinctDP[si][ti] = 0;
    	return 0;
    }

    if(distinctDP[si][ti]!=-1){
    	return distinctDP[si][ti];
    }
        
    int count = 0;
        
    if(s[si]==t[ti]){
        count+=helper(s,si+1,t,ti+1);
    }
    count+=helper(s,si+1,t,ti);
    
    distinctDP[si][ti] = count;

//    for(int i=0;i<6;i++){
//    	for(int j=0;j<4;j++){
//    		cout<<distinctDP[i][j]<<"\t";
//    	}
//    	cout<<endl;
//    }
//    cout<<"*****************"<<endl;

    return count;
}

int main()
{
	cout<<distinctSubsequence("bbaag","bag")<<endl;
	return 0;
}

