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
 
 /*** Recursive code ***/
class Solution {
public:
    
    void helper(TreeNode*root, vector<string>&v, string s){
        
        if(root->left==NULL and root->right==NULL){
            v.push_back(s);
            return;
        }
        
        if(root->left) helper(root->left,v,s + "->" + to_string(root->left->val));
        if(root->right) helper(root->right,v,s + "->" + to_string(root->right->val));
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        
        vector<string>v;
        helper(root,v,to_string(root->val));
        
        return v;
     
        
    }
    
};

/************* Iterative Code *********************/

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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string>res;
        stack<TreeNode*>st;
        st.push(root);
        stack<string>path;
        path.push(to_string(root->val));
        
        while(!st.empty()){
            
            TreeNode*curr = st.top();st.pop();
            string temp_path = path.top();path.pop();
            
            if(curr->left==NULL and curr->right==NULL){
                res.push_back(temp_path);
            }
            
            if(curr->left){
                st.push(curr->left);
                path.push(temp_path+"->"+to_string(curr->left->val));
            }
            if(curr->right){
                st.push(curr->right);
                path.push(temp_path+"->"+to_string(curr->right->val));
            }
        }
        
        return res;
    }
};
