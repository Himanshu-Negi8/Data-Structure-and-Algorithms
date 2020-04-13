class Solution {
public:
    int trap(vector<int>& height) {
        
	int n=height.size(),sum=0; 
	int *l = new int[n];
    int *r = new int[n]; // left most height and right most height array
	
	for(int i=0;i<n;i++)
	{
		l[i]=r[i]=height[i];
		
	}
	for(int i=1;i<n;i++)
	{
		if(l[i-1]>l[i])
		{
			l[i]=l[i-1];
		}
		else
		{
			l[i]=height[i];
		}
		
	}
	
	for(int i=n-2;i>=0;i--)
	{
		if(r[i]>r[i+1])
		{
			r[i]=r[i];
		}
		else
		{
			r[i]=r[i+1];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=min(l[i],r[i])-height[i];
	}
        
	return sum;
        
    }
};
