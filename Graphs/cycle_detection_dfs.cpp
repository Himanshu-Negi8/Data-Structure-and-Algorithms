//cycle detection directed graph
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
	
	bool isCyclicHelper(T node, map<T,bool> &visited, map<T,bool> &inStack){
		
		//processing the current node 
		
		visited[node]=true;
		inStack[node]=true;
		
		//explore the neighbours of the node
		for(T neighbour:adjList[node]){
			//the current node is not visited but its further branch is leanding to cycle
			if((!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack))||inStack[neighbour]){
				return true;
			}
		}
		
		inStack[node]=false;
		return false;
	}
	
	bool isCyclic(){
		
		map<T,bool>visited;
		map<T,bool>inStack;
		
		for(auto i:adjList){
			T node =i.first;
			if(!visited[node]){
				bool cyclePresent = isCyclicHelper(node,visited,inStack);
				if(cyclePresent){
					return true;
				}
			}
		}
		
		return false;
	}
	
	
	
};


int main()
{
	
	
	Graph<int>g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);
	
	cout<<g.isCyclic();
	return 0;
}


