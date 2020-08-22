#include <bits/stdc++.h> 
using namespace std; 
  
bool isReachable(int x, int y,long long dy, long long dx) 
{ 

    if (x > dx || y > dy) 
        return false; 
  
    
    if (x == dx && y == dy) 
        return true; 
  
 
    return (isReachable(x + y, y, dy, dx) ||  
            isReachable(x, y + x, dy, dx)); 
} 

string solve(long long y, long long x){
	
	if(isReachable(1,1,y,x)){
		return "Yes";
	}else{
		return "No";
	}
}

int main() 
{ 

	int t;
	cin>>t;
	while(t){
		int x =1,y=1;
    	int dest_x,dest_y;
    	cin>>dest_x>>dest_y;
    	
    	if (isReachable(x, y, dest_x, dest_y)) 
        	cout << "Yes\n"; 
   		else
        	cout << "No\n"; 
        t--;
	}
    
    return 0; 
} 
