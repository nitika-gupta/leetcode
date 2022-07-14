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
    TreeNode* build(vector<int>& pre,int ps,int pe, vector<int>& in, int is, int ie,unordered_map<int,int> & mp){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int index = mp[pre[ps]];
        int left = index-is;
        
        root->left = build(pre,ps+1,ps+left,in,is,index-1,mp);
        root->right = build(pre,ps+1+left,pe,in,index+1,ie,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i;
        }
        
        
        return build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
    }
};