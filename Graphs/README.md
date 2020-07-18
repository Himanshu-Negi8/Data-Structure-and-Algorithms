# Graph Implementation

```c
#include<bits/stdc++.h>
using namespace std;

class Graph{
	
	int V;
	list<int>*l;
public:
	Graph(int v){
		V=v;
		//array of linked list
		l = new list<int>[V];
	}
	
	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}
	
	void printAdjList(){
		for(int i=0;i<V;i++){
			//l[i] is linked list
			cout<<i<<"->";
			for(int vertex:l[i]){
				cout<<vertex<<" , ";
			}
			cout<<endl;
		}
	}
};


int main()
{
	
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,4);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(4,3);
	g.addEdge(3,2);
	g.printAdjList();

	return 0;
}

```

---

# Graph generic implementation

```c
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
};


int main()
{
	Graph<string> g;
	g.addEdge("putin", "Trump", false);
	g.addEdge("putin", "modi", false);
	g.addEdge("putin", "pope", false);
	g.addEdge("trump", "modi", true);
	g.addEdge("modi", "yogi", true);
	g.addEdge("prabhu", "modi", false);
	g.printGraph();
	
	
	
	Graph<int>g2;
	g2.addEdge(0,1,true);
	g2.addEdge(1,2,false);
	g2.addEdge(0,2,true);
	g2.addEdge(1,3,true);
	g2.addEdge(1,4,true);
	g2.printGraph();
	
	
	return 0;
}



```
---

# BFS Implementation

```c
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
	
	g.bfs(0);
	
	return 0;
}


```