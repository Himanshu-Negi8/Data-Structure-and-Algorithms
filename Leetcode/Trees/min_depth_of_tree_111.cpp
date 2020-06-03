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
    int min =INT_MAX;
public:
    int helper(TreeNode*root,int level){
        
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            min=std::min(level,min);
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
        return min;
    }
    int minDepth(TreeNode* root) {
        
        
        if(!root){
            return 0;
        }
        
        
        
        return helper(root,1);
    }
};
