#include<iostream>
using namespace std;

bool isPalindrome(string s)
{
	int left=0;
	int right = s.length()-1;
	while(left<=right)
	{
		if(s[left]!=s[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int palindromicSubstringCount(string s){
	
int result = 0;
        
    for(int i=0;i<s.length();i++){
            
            //ODD LENGTH
            
        for(int j=0; i-j>=0 and i+j<s.length() ;j++){
            if(s[i-j] == s[i+j]){
                result++;
            }else{
                break;
            }
        }

            //EVEN LENGTH
            
        for(int j=0; i-j>=0 and i+j+1<s.length() ;j++){
            if(s[i-j] == s[i+j+1]){
                result++;
            }else{
                break;
            }
        }
    }
        
    return result;
}


int main()
{
	cout<<palindromicSubstringCount("abba");
	return 0;
}
