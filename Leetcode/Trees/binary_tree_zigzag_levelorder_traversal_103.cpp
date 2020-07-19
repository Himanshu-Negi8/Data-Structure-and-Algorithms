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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        
        vector<vector<int>>v;
        vector<int>p;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            
            TreeNode*f = q.front();
            if(f==NULL){
                q.pop();
                v.push_back(p);
                p.erase(p.begin(),p.end());
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                p.push_back(f->val);
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right)
                {
                    q.push(f->right);
                }
            }
            
        }
        
        for(int i=0;i<v.size();i++){
            if(i&1){
                 reverse(v[i].begin(),v[i].end());  
            }
        }
        return v;
    }
};
