/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>nodes;
    int index;
    BSTIterator(TreeNode* root) {
      
        this->index = -1;
        this->computeInorder(root);
        
    }
    void computeInorder(TreeNode*root){
        if(!root){
            return;
        }
        computeInorder(root->left);
        nodes.push_back(root->val);
        computeInorder(root->right);
        
    }
    
    
    /** @return the next smallest number */
    int next() {
        return this->nodes[++this->index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return this->index+1<this->nodes.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 
 
 //second approach is using stack that allow us to use o(h) space only to meet question requirement

class BSTIterator {
public:
    stack<TreeNode*>s;
    void storeNodes(TreeNode*root){
    	// For a given node, add all the elements in the leftmost branch of the tree
        // under it to the stack.
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        storeNodes(root);
    }
    
    /** @return the next smallest number */
    int next() {
    	// Node at the top of the stack is the next smallest element

        TreeNode*temp = s.top();
        s.pop();
        // Need to maintain the invariant. If the node has a right child, call the 
        // helper function for the right child
        if(temp->right!=NULL){
        	storeNodes(temp->right);
		}
        
        return temp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size()!=0;
    }
};


