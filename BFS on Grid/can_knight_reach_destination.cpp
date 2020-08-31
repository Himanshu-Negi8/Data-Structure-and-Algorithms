#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define REP(i,n) for(int i=1;i<=n;i++) 

#define N 101

using namespace std;


int dx[] ={-2,-1,1,2,2,1,-1,-2};
int dy[]= {1,2,2,1,-1,-2,-2,-1};

int vis[10][10],dist[10][10];

int targetX,targetY;


bool isValid(int x,int y){
	
	if( x>=0 and x<8 and y>=0 and y<8 and vis[x][y]==0) return true;
	
	return false;
}

bool BFS(int x,int y){
	
	
	queue<pair<int,int>>q;
	

	vis[x][y]=1;
	
	q.push({x,y});
	
	if(x==targetX and y==targetY) return true;
	
	while(!q.empty()){
		
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++){
			if(isValid(curr_x+dx[i],curr_y+dy[i])){
				x=curr_x+dx[i];
				y=curr_y+dy[i];
				
				vis[x][y]=1;
				q.push({x,y});
				
				if(x==targetX and y==targetY) return true;
				
			}
		}
	}
	
	return false;
	
}



void displayVisited(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	
	int x,y,q;
	
	cin>>q;
	
	while(q--){

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				vis[i][j]=0;
			}
		}
	
		cin>>x>>y>>targetX>>targetY;
	
		
		cout<<BFS(x,y)<<endl;
		
	}
	
	return 0;
}
