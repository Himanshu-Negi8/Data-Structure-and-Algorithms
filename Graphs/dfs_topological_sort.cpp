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
	
	void dfsHelper(T node, map<T,bool> &visited, list<T> &ordering){
		
		visited[node]=true;
		
		//will call dfs on unvisited neighbours 
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited,ordering);
			}
		}
		
		//at this point all the childern of current node have been visited;
		ordering.push_front(node);
	}
	
	void dfsTopologicalSort(){
		map<T,bool>visited;
		list<T>ordering;
		
		
		for(auto i:adjList){
			// i is pair followed by its neighbour node adjList 
			T node = i.first;
			
			if(!visited[node]){
				dfsHelper(node,visited,ordering);
			}
		}
		
		//print all elements in ordering 
		for(T element:ordering){
			cout<<element<<"-->";
		}
	}
};


int main()
{
	Graph<string>g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","HTML",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("Python","Web Dev",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Dev",false);
	g.addEdge("Java","Web Dev",false);
	
	//g.printGraph(); incase requirement of printing the graph
	
	g.dfsTopologicalSort();
	
	return 0;
}


