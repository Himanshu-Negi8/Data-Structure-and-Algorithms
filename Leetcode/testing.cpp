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

	vector<int>v,p;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	p.push_back(36);
//	priority_queue<int>pq;
//	pq.push(10);
//	pq.push(12);
//	cout<<pq.size();
//	priority_queue<int,vector<int>,greater<int> >pq;
	
   priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> myPq;
   myPq.push(make_pair(v.size(),v));
   myPq.push(make_pair(p.size(),p));
   while(!(myPq.size()==1)){
   	myPq.pop();
   }
   cout<<myPq.top().first ;
//	pq.push(v,v.size());
//	cout<<pq.top().first;
	return 0;

}
