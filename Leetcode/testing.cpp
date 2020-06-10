#include<bits/stdc++.h>
using namespace std;

class temp{

	vector<int>v;
public:
	void set(vector<int>nums){
			this->v = nums;
		}
		void print(){
			for(int i=0;i<this->v.size();i++){
				cout<<this->v[i]<<" ";
			}
		}
};

int main()
{
//	vector<int>v,nums;
//	
//	v.push_back(2);
//	v.push_back(3);
//	temp obj;
//	obj.set(v);
//	obj.print();
//	nums.push_back(245);
//	nums.push_back(435);
//	temp ob;
//	ob.set(nums);
//	ob.print();

	vector<int>v(4);
	v[0]=1;
	v[1]=3;
	v[2]=5;
	v[3]=6;
	
	for(int i:v){
		cout<<i<<" ";
	}
	cout<<endl;
	if(binary_search(v.begin(),v.end(),5)){
		auto lb = lower_bound(v.begin(),v.end(),5)-v.begin();
		
		cout<<lb;
	}
	return 0;

}
