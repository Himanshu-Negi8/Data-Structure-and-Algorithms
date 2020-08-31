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

//#define N 101

using namespace std;


int dist[1001][1001],vis[1001][1001];
int N,M;


bool isValid(int x,int y){
	if(x<0 || x>=N || y<0|| y>=N){
		return false;
	}
	if(vis[x][y]) return false;
	return true;
}

int dx[]={-1,0,1,0};
int dy[]= {0,1,0,-1};
void bfs(int srcX, int srcY){
	
	queue<pair<int,int>>q;
	
	q.push({srcX,srcY});
	dist[srcX][srcY]=0;
	vis[srcX][srcY]=1;
	
	while(!q.empty()){
		
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			if(isValid(curr_x+dx[i],curr_y+dy[i])){
				int new_x = curr_x+dx[i];
				int new_y = curr_y+dy[i];
				
				dist[new_x][new_y] = dist[curr_x][curr_y]+1;
				vis[new_x][new_y]=1;
				q.push({new_x,new_y});
			}
		}
	}
	
	cout<<"Distance Array"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<setw(3)<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	int x,y;
	cin>>N>>M;
	cin>>x>>y;
	bfs(x,y);
	return 0;
}
