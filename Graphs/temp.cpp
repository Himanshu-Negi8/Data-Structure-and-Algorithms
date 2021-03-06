#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	
	unordered_map<T,list<pair<T,int>>>adjList;
public:
	void addEdge(T u, T v, int dist, bool bidir=true){
		
		adjList[u].push_back(make_pair(v,dist));
		if(bidir){
			adjList[v].push_back(make_pair(u,dist));
		}
	}
	
	void printAdj(){
		//iterate over all key value pairs
		for(auto i:adjList){
			//i.first is the key or node
			cout<<i.first<<" ";
			//i.second is the list of neighbours
			for(auto l:i.second){
				//inside list there is pair where l.first is neighbour node and l.second is weight or we can say distance
				cout<<"("<<l.first<<" "<<l.second<<") ";
			}
			cout<<endl;
		}
	}
	
	void dijkstra(T src){
		
		unordered_map<T,int>dist;
		
		for(auto node:adjList){
			dist[node.first]=INT_MAX;
		}
		set<pair<int,T>>s;
		dist[src]=0;
		
		s.insert(make_pair(0,src));
		
		while(!s.empty()){
			
			
			auto p =*(s.begin());
			T node = p.second;
			int nodeDist = dist[node];
			
			s.erase(s.begin());
			
			for(auto childPair:adjList[node]){
				if(nodeDist+childPair.second<dist[childPair.first]){
					
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
					}
					
					dist[dest]= nodeDist+childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		
		for(auto d:dist){
			cout<<"Distance of "<<d.first<<" from "<<src<<" is "<<d.second<<endl;
		}
		
		
		
	}
	
	
};


int main(){
	
	Graph<int>g;
	
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(1,4,7);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	
	g.printAdj();
	g.dijkstra(1);
	
	return 0;
	
}
