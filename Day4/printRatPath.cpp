#include<iostream>
using namespace std;


bool ratInMaze(char maze[][4],int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return true;
	}

	if(sr>er or sc>ec){
		return false;
	}

	if(maze[sr][sc]=='X'){
		return false;
	}

	bool horizontal = ratInMaze(maze,sr,sc+1,er,ec);
	bool vertical = ratInMaze(maze,sr+1,sc,er,ec);

	return horizontal or vertical;
}

void printRatInAMaze(char maze[][4],int sol[][4],int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec){
		for(int i=0;i<er;i++)
		{
			for(int j=0;j<ec;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl; 
		}
		cout<<"*********";
	}
	if(sr>er or sc>ec){
		return ;
	}

	if(maze[sr][sc]=='X'){
		return ;
	}
	sol[sr][sc]=1;
	bool horizontal = printRatInAMaze(maze,sol,sr+1,sc,er,ec);
	bool vertical = printRatInAMaze(maze,sol,sr,sc+1,er,ec);
	sol[sr][sc]=0;

	return;
} 

int main(){

	int board[4][4] = {0};
	int n = 4;

	// cout<<NQueens(board,0,n)<<endl;

	// printNQueens(board,0,n);

	// cout<<countNQueens(board,0,n)<<endl;

	char maze[][4] = {
     	{'0','0','0','0'},
     	{'0','0','0','0'},
     	{'0','0','X','0'},
     	{'0','X','0','0'},
     };

    // cout<<ratInMaze(maze,0,0,3,3)<<endl;

     int sol[4][4] = {0};

    printRatInAMaze(maze,sol,0,0,4,4);
    

	return 0;
}
