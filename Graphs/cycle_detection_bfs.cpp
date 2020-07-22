// cycle detection for undirected graph

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
	
	//check for undirected graph
	bool isCyclicBFS(T src){
		
		map<T,bool>visited;
		map<T,T>parent;
		queue<T>q;
		q.push(src);
		visited[src]=true;
		parent[src]=src;
		
		while(!q.empty()){
			T node = q.front();
			q.pop();
			
			//iterate overs the neighbour of node
			
			for(T neighbour:adjList[node]){
				// the conditon  is used to check whether the negihbour is already visited or not 
				// and also check whether the parent of current node is not the neighbour 
				//because the parent of node is neighbour same as parent it will return true in that case also, we put the negative conditon
				//as every time we had already visited the parent and parent is also its neighbour it is basically exception
				if(visited[neighbour]==true and parent[node]!=neighbour){ 
					return true;	
				}
				
				else if(!visited[neighbour]){
					visited[neighbour]=true;
					parent[neighbour]=node;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
	
	
	
};


int main()
{

	
	
	Graph<int>g;
	g.addEdge(0,1);
//	g.addEdge(1,4);
//	g.addEdge(2,3);
//	g.addEdge(4,3);
	
	
	if(g.isCyclicBFS(1)){
		cout<<"Cyclic Graph";
	}else{
		cout<<"Not cyclic graph";
	}
	
	
	
	return 0;
}


