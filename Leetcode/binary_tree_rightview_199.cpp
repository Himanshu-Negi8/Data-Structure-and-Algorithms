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
    vector<int>helper(TreeNode*root,vector<int>&v,int height)
    {
        if(height==v.size()){
                v.push_back(root->val);     
        }
        
        if(root->right)
             helper(root->right,v,height+1);
        if(root->left)
             helper(root->left,v,height+1);
        
        

        return v;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root){
            return {};
        }
        vector<int>v;
        return helper(root,v,0);
    }
};
