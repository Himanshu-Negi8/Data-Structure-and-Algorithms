#include<iostream>
using namespace std;

bool isSafe(int board[][4],int row,int col,int n)
{
	for(i=0;i<row;i++)
	{
		if(board[i][col])
	}
}

bool ratInMaze(int board[][4],row,n)
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
return 0;
}
