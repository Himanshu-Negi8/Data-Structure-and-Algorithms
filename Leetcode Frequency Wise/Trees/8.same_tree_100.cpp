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
    void fillQueue(TreeNode*root,queue<TreeNode*>&q){
        if(!root){
            q.push(NULL);
            return;
        }
        q.push(root);
        fillQueue(root->left,q);
        fillQueue(root->right,q);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*>first,second;
        fillQueue(p,first);
        fillQueue(q,second);
        
        while(!first.empty()){
            TreeNode * a = first.front(); first.pop();
            TreeNode *b = second.front();second.pop();
            if(a==NULL and b!=NULL){
                return false;
            }
            else if(b==NULL and a!=NULL){
                return false;
            }
            else if(!a and !b){
                continue;
            }
            else if(a->val == b->val){
                continue;
            }else{
                return false;
            }
        }
        
        if(first.empty() and second.empty()){
            return true;
        }else{
            return false;
        }
    }
};





