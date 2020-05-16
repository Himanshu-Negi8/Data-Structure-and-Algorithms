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
    
    
    int helper(TreeNode*root,TreeNode*parent,int &sum){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL && parent->left==root){
            sum+=root->val;
        }
        helper(root->left,root,sum);
        helper(root->right,root,sum);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int  sum=0;
       if(root==NULL){
           return 0;
       }
        helper(root->left,root,sum);
        helper(root->right,root,sum);
        return sum;
    }
};
