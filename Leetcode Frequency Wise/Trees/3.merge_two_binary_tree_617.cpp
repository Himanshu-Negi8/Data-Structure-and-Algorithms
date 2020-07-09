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
 
//recursive approach
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(!t2){
            return t1;
        }
        
        if(!t1){
            return t2;
        }
        
        t1->val+=t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
        
        
    }
};


//iterative
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        
        stack<TreeNode*>s;
        s.push(t1);
        s.push(t2);
        while(!s.empty()){
            TreeNode *a,*b;
            b=s.top(); s.pop();
            a=s.top();  s.pop();
            
            if(!a || !b){
                continue;
            }
            
            a->val += b->val;
            
            if(!a->left){
                a->left = b->left;
            }else{
                s.push(a->left);
                s.push(b->left);
            }
            if(!a->right){
                a->right =b->right;
            }else{
                s.push(a->right);
                s.push(b->right);
            }
        }
        return t1;
    }
};
