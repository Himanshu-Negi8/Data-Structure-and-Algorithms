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
	
	int bfs(T src, T dest){
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
			
			//which are not visited neighbours of current node
			for(T neighbour:adjList[node]){
				if(dist[neighbour]==INT_MAX){
					q.push(neighbour);
					dist[neighbour]=dist[node]+1;
					parent[neighbour]=node;
				}
				
			}
		}
		

		//you have destination and go backwards
		T temp = dest;
		while(src!=temp){
			cout<<temp<<" <-- ";
			temp=parent[temp];
		}
		cout<<src<<endl;
		return dist[dest];
		
	}
};

// in this just construct the graph all code is same like bfs used in traversal and single soure shortest path(SSSP)
int main()
{
	Graph<int>g;
	
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	
	// construct the graph, add pair (u,v)
	
	
	for(int u=0;u<=36;u++){
		//at every node we can through a dice
		
		for(int dice=1;dice<=6;dice++){
			int v = u+dice+board[u+dice];
			
			g.addEdge(u,v,false);
		}
	}
	
	
	
	cout<<g.bfs(0,36);
	
	return 0;
}


