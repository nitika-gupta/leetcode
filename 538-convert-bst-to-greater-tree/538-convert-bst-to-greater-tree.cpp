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
    int bs(int x, vector<int> &v){
        int l=0;
        int h=v.size();
        
        while(l<=h){
           int mid =(l+h)/2;
        if(v[mid]==x)
            return mid;
        else if(v[mid]<x)
            l=mid+1;
        else
            h=mid-1;
        }
        return -1;
    }
    void findsum(TreeNode* root,vector<int>&v){
        if(root==NULL)
            return;
        int ind= bs(root->val,v);
    
        for(int i=ind+1;i<v.size();i++ ){
            root->val+=v[i];
        }
        
        findsum(root->left,v);
        findsum(root->right,v);
        
        
        
    }
    
    void in(TreeNode* root,vector<int> &v){
         if(root==NULL){
            return;
        }
       
        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<int> v;
        in(root,v);
        findsum(root,v);
        return root;
    }
};