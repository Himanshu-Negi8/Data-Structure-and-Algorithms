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
 
// itearative approach using queue 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
       if(!root){
           return root;
       }
        std::queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode*current = q.front();
            q.pop();
            TreeNode*temp = current->left;
            current->left = current->right;
            current->right = temp;
            
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
            
        }
        return root;
    }
    
};

//recursive approach

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root){
            return root;
        }
        
        TreeNode*temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
    
};

