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
    TreeNode*helper(TreeNode*root,int val){
        TreeNode*temp = new TreeNode();
        temp->val =val;
        temp->left=temp->right=NULL;
        if(root==NULL){
            root=temp;
            return root;
        }
            
        if(root->val>val){
            root->left = helper(root->left,val);
        }else if(root->val<=val){
            root->right = helper(root->right,val);
        }
        
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode*root=NULL;
        for(int val:preorder){
            root=helper(root,val);
        }
        return root;
    }
};
