#include "solution.hpp"
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
 
       1      (Level 0 = 1)
      / \
     2   3    (Level 1 = 2 + 3)
        / \
       4   5  (Level 2 = 4 + 5)
class Solution {
    public:
    int solve(Tree* root) {
        // Write your code here
         if(!root) return 0;
        
        queue<Tree*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int min_sum=INT_MAX;
        int i=0;
        int curr_level=0;
        while(!q.empty()){
            
            Tree*f = q.front();
            
            if(f==NULL){
                q.pop();
                
                if(min_sum>sum){
                    min_sum=sum;
                    i=curr_level;
                }
                sum=0;
                curr_level++;
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

