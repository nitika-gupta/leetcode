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
    
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lst=diameter(root->left);
        int rst=diameter(root->right);
        return(1 +max(lst,rst));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh =diameter(root->left);
         int rh =diameter(root->right);
        return max(lh+rh,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};