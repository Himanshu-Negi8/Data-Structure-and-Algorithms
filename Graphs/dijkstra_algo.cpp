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
	
	void dijkstraSSSP(T src){
		
		
		unordered_map<T,int>dist;
		
		//set all distances to infinity
		for(auto j:adjList){
			dist[j.first]=INT_MAX;
		}
		
		//make a set to find out a node with minium distacne;
		set<pair<int,T>>s;
		dist[src]=0;
		
		s.insert(make_pair(0,src));
		
		while(!s.empty()){
			
			//find the pair at the front
			
			auto p = *(s.begin());
			T node = p.second; //second parameter denotes the node
			int nodeDist = p.first;//first parameter denotes the dist
			
			s.erase(s.begin());
			
			//iterate over the neighbours
			for(auto childPair:adjList[node]){
				if(nodeDist+childPair.second<dist[childPair.first]){
					
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
						
					}
					//insert the new pair
					dist[dest]=nodeDist+childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
			
		}
		
		//print dist to all other nodes
		
		for(auto d:dist){
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
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
	g.dijkstraSSSP(1);
	
	
	
	Graph<string>india;
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Jaipur","Delhi",2);
	india.addEdge("Jaipur","Mumbai",8);
	india.addEdge("Bhopal","Agra",2);
	india.addEdge("Mumbai","Bhopal",3);
	india.addEdge("Agra","Delhi",1);
	
	india.printAdj();
	india.dijkstraSSSP("Amritsar");
	
	
	return 0;
}
