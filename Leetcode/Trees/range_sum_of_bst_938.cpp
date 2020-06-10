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
    void helper(TreeNode*root,int L,int R,int &sum){
        if(!root){
            return;
        }
        if(root->val>=L && root->val<=R){
            sum+=root->val;
        }
        
        if(L<root->val){
            helper(root->left,L,R,sum);
        }
        if(R>root->val){
            helper(root->right,L,R,sum);
        }
        
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root){
            return 0;
        }
        int sum=0;
        helper(root,L,R,sum);
        return sum;
    }
};
