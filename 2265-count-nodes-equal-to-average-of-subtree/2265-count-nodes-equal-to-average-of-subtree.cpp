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
    
    int res=0;
    int avg(TreeNode * root, int &count){
        if(root==NULL)
            return 0;
        count++;
        int l=avg(root->left,count);
        int r=avg(root->right,count);
        return (root->val +l+r);
        
        
    }
    void in(TreeNode * root){
        if(root==NULL)
            return;
        int count=0;
        in(root->left);
        if(root->val==avg(root,count)/count)
            res++;
        
        in(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        res=0;
        in(root);
        return res;
    }
};