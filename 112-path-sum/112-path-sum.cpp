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
    
    bool solve(TreeNode* root,int t,int sum){
        if(root==NULL)
            return false;
        if( root->left==NULL && root->right==NULL){
            if((sum + root->val)==t){
                return true;
            }
            return false;
          
        }
          return (solve(root->left,t,sum+root->val) ||solve(root->right,t,sum+root->val));
   
     
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        
        
        return(solve(root,targetSum,0));
    }
};