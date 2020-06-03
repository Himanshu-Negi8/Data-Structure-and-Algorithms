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
	vector<int>v,nums;
	
	v.push_back(2);
	v.push_back(3);
	temp obj;
	obj.set(v);
	obj.print();
	nums.push_back(245);
	nums.push_back(435);
	temp ob;
	ob.set(nums);
	ob.print();
	return 0;
}
