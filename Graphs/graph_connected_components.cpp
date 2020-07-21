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
	
	void dfsHelper(T node, map<T,bool> &visited){
		//whenever come to a node make it visited
		visited[node]=true;
		cout<<node<<" ";
		
		
		
		//try to find out the neighbour and not visited yet
		
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
		
	}
	
	
	void dfs(T src){
		map<T,bool>visited;
		
		int component = 1;
		
		dfsHelper(src,visited);
		
		cout<<endl;
		for(auto i:adjList){
			T city = i.first;
			if(!visited[city]){
				//called dfsHelper again for those which are not visited by source 
				dfsHelper(city,visited);
				component++;
			}
		}
		cout<<endl;
		cout<<"The number of components in this graph "<<component<<" ";
	}
	
	
	
};


int main()
{
	
	
	
	Graph<string>g;
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Bangalore");
	g.addEdge("Agra","Delhi");
	g.addEdge("Andman","Nicobar");
	

	g.dfs("Amritsar");
	
	
	return 0;
}


