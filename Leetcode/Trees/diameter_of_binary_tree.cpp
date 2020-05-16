/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
	if(root==NULL){
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight,rightHeight) + 1;
}
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
		return 0;
	}

	int leftDiameter = diameterOfBinaryTree(root->left);
	int rightDiameter = diameterOfBinaryTree(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalDiamter = max(leftHeight+rightHeight+2,max(leftDiameter,rightDiameter));
	return totalDiamter;
    }
};
