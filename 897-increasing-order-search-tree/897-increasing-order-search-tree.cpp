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
    
    void in(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        in(root->left,ans);
        ans.push_back(root->val);
        in(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<int> ans;
        
        in(root,ans);
        
        TreeNode* head=new TreeNode(ans[0]);
        TreeNode* temp=head;
        
        for(int i=1;i<ans.size();i++){
            temp->right=new TreeNode(ans[i]);
            temp=temp->right;
            
        }
        return head;
        
        
    }
};