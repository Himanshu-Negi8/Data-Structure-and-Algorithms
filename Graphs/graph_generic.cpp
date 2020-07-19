#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	
	map<T,list<T>>adjList;
public:
	
	 Graph(){
		
	}
	void addEdge(T u, T v, bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	
	void printGraph(){
		//iterate over map
		for(auto i : adjList){
			//i.first is the key
			cout<<i.first<<"->";
			//i second is name of person i follows
			for(auto entry:i.second){
				cout<<entry<<" ,";
			}
			cout<<endl;
		}
	}
	
	
	
};


int main()
{
	Graph<string> g;
	g.addEdge("putin", "Trump", false);
	g.addEdge("putin", "modi", false);
	g.addEdge("putin", "pope", false);
	g.addEdge("trump", "modi", true);
	g.addEdge("modi", "yogi", true);
	g.addEdge("prabhu", "modi", false);
	g.printGraph();
	
	
	
	Graph<int>g2;
	g2.addEdge(0,1,true);
	g2.addEdge(1,2,false);
	g2.addEdge(0,2,true);
	g2.addEdge(1,3,true);
	g2.addEdge(1,4,true);
	g2.printGraph();
	
	
	return 0;
}


