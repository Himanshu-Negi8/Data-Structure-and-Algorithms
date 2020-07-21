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
	
	void bfsTopologicalSort(){
		queue<T>q;
		map<T,bool>visited;
		map<T,int>indegree;
		
		for(auto i:adjList){
			T node = i.first;
			visited[node]=false;
			indegree[node]=0;
		}
		
		//increment the indegree of neighbours of node 
		
		for(auto i:adjList){
		
			for(T neighbour:adjList[i.first]){
				indegree[neighbour]++;
			}
		}
		
		
		//push all the nodes in queue whose indegree is zero initially
		for(auto i:adjList){
			T node = i.first;
			if(indegree[node]==0){
				q.push(node);
			}
		}
		
		
		//start with algorithm
		while(!q.empty()){
			T node =q.front();
			q.pop();
			cout<<node<<" ";
			
			for(T neighbour:adjList[node]){
				indegree[neighbour]--; 
				//if any point the indegree of neighbour become zero push it in the queue
				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		} 
		
		
	}
	
	
	
};


int main()
{
	
	
	// the idea is to resolve those nodes first whose indegree is zero 
	
	Graph<int>g;
	g.addEdge(0,2,false);
	g.addEdge(1,2,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
	g.addEdge(4,5,false);
	g.addEdge(3,5,false);
	g.printGraph();
	g.bfsTopologicalSort();
	
	
	Graph<string>g2;
	g2.addEdge("English","Programming Logic",false);
	g2.addEdge("Maths","Programming Logic",false);
	g2.addEdge("Programming Logic","HTML",false);
	g2.addEdge("Programming Logic","Python",false);
	g2.addEdge("Programming Logic","Java",false);
	g2.addEdge("Programming Logic","JS",false);
	g2.addEdge("Python","Web Dev",false);
	g2.addEdge("HTML","CSS",false);
	g2.addEdge("CSS","JS",false);
	g2.addEdge("JS","Web Dev",false);
	g2.addEdge("Java","Web Dev",false);
	g2.bfsTopologicalSort();
	
	
	return 0;
}


