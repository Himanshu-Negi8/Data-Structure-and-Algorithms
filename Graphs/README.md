# Graph Implementation :smiley:

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

# Generic Graph Implementation

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

# Graph BFS Implementation

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


```

# Graph DFS Implementation

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
		
		dfsHelper(src,visited);
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
	
	g.dfs(0);
	
	
	return 0;
}


```

---

# Graph Snake and Ladder Problem 

![](snake_and_ladder_problem.png)

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



```

