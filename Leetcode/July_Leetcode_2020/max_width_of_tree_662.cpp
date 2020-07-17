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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;

        
        queue<pair<TreeNode*,int>>q;
        int result=1;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result,end-start+1);
            
            for(int i=0;i<count;i++){
                pair<TreeNode*,int>p=q.front();
                int idx =p.second-start;
                q.pop();
                if(p.first->left) q.push(make_pair(p.first->left,2*idx+1));
                if(p.first->right) q.push(make_pair(p.first->right,2*idx+2));
            }
        }
        return result;
        
    }
};
