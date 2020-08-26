#include<iostream>
using namespace std;

bool isPalindrome(string str,int left,int right){
	while(left<=right){
		if(str[left]!=str[right]){
			return false;
		}
		left++;
		right--;
	}

	return true;
}

int palindromePartitioning(string str,int start,int end){
	if(start>end){
		return 0;
	}

	if(start==end){
		return 0;
	}

	if(end-start ==1){
		return str[start]==str[end] ? 0 : 1;
	}

	if(isPalindrome(str,start,end)){
		return 0;
	}

	int minValue = INT_MAX;

	for(int i=start;i<end;i++){

		int leftCuts = palindromePartitioning(str,start,i);
		int rightCuts = palindromePartitioning(str,i+1,end);

		minValue = min(minValue,leftCuts + 1 + rightCuts);
	}

	return minValue;
}




int main()
{
	return 0;
}
