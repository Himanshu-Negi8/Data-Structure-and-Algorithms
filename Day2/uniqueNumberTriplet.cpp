#include<iostream>
using namespace std;


void uniqueNumberTriplet(int arr[],int n){

	int bitAdder[32] = {0};

	for(int i = 0;i<n;i++){

		int var = arr[i];

		for(int j=31;j>=0;j--){

			bitAdder[j]+=(var&1);
			var = var>>1;
		}
	}

	

	int decimal = 0;

	int multiply = 1;

	for(int i = 31;i>=0;i--){
		bitAdder[i] = bitAdder[i]%3;

		decimal = decimal + multiply*bitAdder[i];
		multiply = multiply<<1;
	}

	cout<<"Unique value is "<<decimal<<endl;
}

int main()
{
	
	int arr[] = {1,1,1,2,2,2,0,4,4,4};
	int n = 10;

	uniqueNumberTriplet(arr,n);

	return 0;
}
