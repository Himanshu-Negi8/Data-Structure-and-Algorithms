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
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int max_sum=INT_MIN;
        int i=0;
        int curr_level=0;
        while(!q.empty()){
            
            TreeNode*f = q.front();
            
            if(f==NULL){
                q.pop();
                curr_level++;
                if(max_sum<sum){
                    max_sum=sum;
                    i=curr_level;
                }
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
                
            }else{
                sum+=f->val;
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
            
            
        }
        return i;
    }
};
