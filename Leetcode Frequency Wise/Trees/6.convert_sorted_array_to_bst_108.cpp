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
    TreeNode*convertToBST(int left,int right,vector<int>&v){
        
        if(left>right){
            return NULL;
        }
        
        int mid = (left+right)/2;
        TreeNode*node = new TreeNode(v[mid]);
        
        if(left==right){
            return node;
        }
        
        node->left = convertToBST(left,mid-1,v);
        node->right = convertToBST(mid+1,right,v);
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        
        return convertToBST(0,nums.size()-1,nums);
    
    }
};
