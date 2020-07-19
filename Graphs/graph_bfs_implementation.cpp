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
	
	void bfs(T src){
		queue<T>q;
		map<T,bool>visited;
		q.push(src);
		visited[src]=true;
		
		while(!q.empty()){
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			
			//which are not visited neighbours of current node
			for(T neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
				}
				
			}
		}
		
	}
	
	
	//finding the single source shortest path using bfs traversal
	void distance(T src, T dest){
		queue<T>q;
		
		map<T,int>dist;
		
		map<T,T>parent;
		
		
		for(auto i:adjList){
			dist[i.first]=INT_MAX;
		}
		
		
		q.push(src);
		dist[src]=0;
		parent[src]=src;
		
		while(!q.empty()){
			T node = q.front();
			cout<<node<<" "; //you can print nodes level order wise as well
			q.pop();
			
			//which are not visited neighbours of current node
			for(T neighbour:adjList[node]){
				if(dist[neighbour]==INT_MAX){
					q.push(neighbour);
					dist[neighbour]=dist[node]+1;
					parent[neighbour]=node;
				}
				
			}
		}
		
		//printing the distance
		for(auto i:adjList){
			T node = i.first;
			cout<<"Dist of this "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
			
		}
		
		// incase you want to see the path as well then parent map will come in working
		 T node = dest;
		 while(src!=node){
		 	cout<<node<<" parent is "<<parent[node]<<"  ";
		 	node = parent[node];
		 }
		
	}
	
	
	
};


int main()
{

	Graph<int>g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	
//	g.bfs(0);
	g.distance(0,5);
	
	return 0;
}


