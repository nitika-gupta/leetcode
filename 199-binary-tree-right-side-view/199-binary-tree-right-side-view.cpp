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
    void travel(TreeNode* root,vector<int>& res, int &level, int cur){
        if(!root){return;}
        
        if(level<cur){
            res.push_back(root->val);
            level=cur;
        }
        travel(root->right,res,level,cur+1);
        travel(root->left,res,level,cur+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        if(root==NULL){
            return res;
        }
        int level=0;
        travel(root,res,level,1);
        return res;
    }
};