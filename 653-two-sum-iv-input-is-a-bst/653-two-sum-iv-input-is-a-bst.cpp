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
    TreeNode* solve(TreeNode* root, int k, unordered_map<int,int> &mp){
        
        if(root==NULL)
            return NULL;
        
        TreeNode* lft = solve(root->left, k,mp);
        if(lft!=NULL)
            return lft;
        if(mp.find(root->val)!=mp.end())
            return root;
        else{
            mp[k-root->val]++;
            
        }
        return solve(root->right,k,mp);
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int,int> mp;
        TreeNode* res=solve(root,k,mp);
        if(res==NULL)
            return false;
        return true;
        
    }
};