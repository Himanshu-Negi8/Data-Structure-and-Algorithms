class Solution {
public:
    
    void helper(TreeNode*root,vector<int>&v){
        if(!root){
            return;
        }
        if(root){
            helper(root->left,v);
            v.push_back(root->val);
            helper(root->right,v);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
            
            vector<int>v;
            helper(root,v);
            int i=0;
        
            
            while(k!=0){
                k--;
                i++;  
            }
        
        return v[--i];
    }
};
