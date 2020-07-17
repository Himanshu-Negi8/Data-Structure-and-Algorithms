#include<bits/stdc++.h>
using namespace std;


class node
{
	public:
	int data;
	node*left;
	node*right;
	
	node(int d)
	{
		data=d;
		left=right=NULL;
	}
};

//build the tree 
node*buildTree()
{
	int d;
	cin>>d;
	if(d==-1) 
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = buildTree(); 
	root->right =buildTree();
	return root;
}
//total leaf nodes

int leafNodes(node*root){
	
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL&&root->right==NULL){
		return 1;
	}
	return leafNodes(root->left)+leafNodes(root->right);
}

//total nodes having left child only

int countleftChildOnly(node*root){
	
	if(root==NULL){
		return 0;
	}
	if(root->left!=NULL && root->right==NULL){
		//printf("%d  ",root->data); // incase want to show which nodes having the specified
		return 1+countleftChildOnly(root->left);
	}
	return countleftChildOnly(root->left)+countleftChildOnly(root->right);
}

//total nodes having right child only

int countrightChildOnly(node*root){
	
	if(root==NULL){
		return 0;
	}
	if(root->right!=NULL && root->left==NULL){
		
		//printf("%d  ",root->data); // incase want to show which nodes having the specified
		return 1+countrightChildOnly(root->right);
	}
	return countrightChildOnly(root->right)+countrightChildOnly(root->left);
}

//printing a tree or we can say it is a preorder print recursive calls
void print(node*root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
//code for inorder print recursive calls 
void printIn(node*root)
{
	if(root==NULL)
	{
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right); 
}

//code for print the tree in postorder or bottom-up using recursive calls
void printPost(node*root)
{
	if(root==NULL)
	{
		return;
	}
	printPost(root->left);
	printPost(root->right); 
	cout<<root->data<<" ";
}

int height(node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	return max(left,right)+1;
}

void printKthlevel(node*root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printKthlevel(root->left,k-1);
	printKthlevel(root->right,k-1);
}

void printAllLevels(node*root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
	{
		printKthlevel(root,i);
		cout<<endl; 
	}
}
int countNodes(node*root){
	
	if(root==NULL){
		return 0;
	}
	int left = countNodes(root->left);
	int right=countNodes(root->right);
	return left+right+1;
}


//printing the level wise tree in O(n) time
void bfs(node*root) {

	queue<node*>q;
	
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		
		node*f = q.front();
		
		if(f==NULL)
		{
				cout<<endl;
				q.pop();
				if(!q.empty()){
					q.push(NULL);
				}
		}else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
		
	}
	return;
}

int sumOfAllNodes(node*root){
	
	if(root==NULL){
		return 0;
	}
	int leftSum = sumOfAllNodes(root->left);
	int rightSum = sumOfAllNodes(root->right);
	
	return leftSum+rightSum+root->data;
}

bool search(node*root,int key){
	
	if(root==NULL){
		return false;
	}
	
	if(root->data==key){
		return true;
	}
	bool leftSearch = search(root->left,key);
	bool rightSearch = search(root->right,key);
	

	 return leftSearch or rightSearch;
}

int diameter(node*root){
	
	if(root==NULL){
		return 0;
	}
	
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1,max(op2,op3));
}


int replaceParentWithChildSum(node*root){
	
	if(root==NULL){
		return 0;
	}
	
	if(root->left==NULL&&root->right==NULL){
		return root->data;
	}
	
	int leftSum = replaceParentWithChildSum(root->left);
	int rightSum =replaceParentWithChildSum(root->right);
	
	root->data = rightSum+leftSum;
	return root->data;
	
	
}

bool checkSiblings(node*root,int a,int b)
{
	if(!root){
		return false;
	}
	
	if(root->left&&root->right){
		int x= root->left->data;
		int y = root->right->data;
		if((x==a && y==b)||(x==b && y==a))
		{
			return true;
		}
		
	}
	
	if(root->left){
		checkSiblings(root->left,a,b);
	}
	if(root->right){
		checkSiblings(root->right,a,b);
	}
}
int main()
{
	node*root = buildTree();
	cout<<"in order traversal of tree : ";
	printIn(root);
	cout<<endl;
	cout<<"height of the treee is : "<<height(root)<<endl;

//	printKthlevel(root,3);

	cout<<"level wise printing of tree : "<<endl;
	printAllLevels(root);
	cout<<endl;
	
	cout<<"Number of nodes : "<<countNodes(root)<<endl;
	
	cout<<"Level order traversal bfs efficient : \n";
	bfs(root); 
	cout<<endl;
	
	cout<<"Sum of all nodes : "<<sumOfAllNodes(root)<<endl; 
	cout<<"Diameter of tree is : "<<diameter(root)<<endl;
//	replaceParentWithChildSum(root);
//	bfs(root);
	
	cout<<endl;;
	
//	cout<<checkSiblings(root,10,3)<<endl;
	innt key;
	cin>>key;
	cout<<search(root,key)<<endl;
	return 0;
	
}
// input for tree is : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
