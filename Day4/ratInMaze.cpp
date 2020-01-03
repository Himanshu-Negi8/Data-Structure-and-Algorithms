#include<iostream>
using namespace std;

bool isSafe(char board[][4],int row,int col,int n)
{
	for(int i=0;i<row;i++)
	{
		if(board[i][col]=='X')
		{
			return false;
		}
	}
	return true;
}

bool ratInMaze(char board[][4],int row,int n)
{
	if(row==n)
	{
		return true;
	}
	
	for(int col=0;col<n;col++)
	{
		if(isSafe(board,row,col,n))
		{
			board[row][col]=1;
			bool rest_of_maze = ratInMaze(board,row+1,n);
			if(rest_of_maze)
			{
				return true;
			}
			board[row][col]=0;
		}
	}
}


int main()
{
	char maze[][4] = {
     	{'0','0','0','0'},
     	{'0','0','0','0'},
     	{'0','0','X','0'},
     	{'0','X','0','0'},
     };
     
     cout<<ratInMaze(maze,4,5);
return 0;
}
