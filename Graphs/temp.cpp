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
	
	void print(){
		
		for(auto i:adjList){
			cout<<i.first<< " -> ";
			for(auto neighbours:i.second){
				cout<<neighbours<<" , ";
			}
			cout<<endl;
		}
	}
	
	void bfs(T src){
		queue<T>q;
		q.push(src);
		map<T,bool>visited;
		
		visited[src]=true;
		while(!q.empty()){
			T node = q.front();
			cout<<node<<" , ";
			q.pop();
			for(T neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
				}
			}
		}
	}
	
	void dist(T src){
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
			q.pop();
			
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
			cout<<" Dist of this "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
		}
		
	}

};


int main(){
	Graph<int>g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,5);
	g.addEdge(1,2);
	
//	g.print();
//	g.bfs(0);
	g.dist(0);
	
	return 0;
}
