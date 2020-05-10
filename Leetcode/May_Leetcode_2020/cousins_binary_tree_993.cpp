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
    int flg=0;
    pair<int,int> findParentAndDepth(TreeNode * root, int x, int depth) {
        pair<int,int> ans;
        if(root == NULL){
            return {-1,-1};
        }
        if(root->left != NULL && root->left->val == x){
            flg=1;
            ans =  {depth+1, root->val};
            return ans;
        }
        if(root-> right != NULL && root->right->val == x){
            flg=1;
            ans = {depth+1, root->val};
            return ans;
        }
        if(root->left != NULL){
             ans =  findParentAndDepth(root->left, x, depth+1);
            if(flg)
                return ans;
        }
        if(root->right != NULL){
            ans =  findParentAndDepth(root->right, x, depth+1);
            if(flg)
                return ans;
        }
        return {-1,-1};
    }
    bool isCousins(TreeNode* root, int x, int y) {
        flg=0;
        pair<int,int>a = findParentAndDepth(root,x,0);
        flg=0;
        pair<int,int>b = findParentAndDepth(root,y,0);
        
        
        if(a.first == b.first && a.second != b.second)
            return true;
        else
            return false;
        
    }
};
