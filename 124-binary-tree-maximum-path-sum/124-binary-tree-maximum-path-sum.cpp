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
//     int sum(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
        
//         int lst=sum(root->left);
//         int rst=sum (root->right);
//         return(max(root->val + max(lst,rst), root->val));
//     }
                                                         
    
    int solve(TreeNode* root, int& res){
        if(root==NULL){
            return 0;
        }
        
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        int temp=max(max(l,r)+root->val,root->val );
        int ans=max(temp, l+r+root->val);
        res=max(ans,res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
       
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
    
    
    /* if(root->left ==NULL && root->right==NULL){
            return root->val;
        }
        int lh =sum(root->left);
         int rh =sum(root->right);
        return  max(root->val +lh+rh,max(maxPathSum(root->left),maxPathSum(root->right)));*/
};