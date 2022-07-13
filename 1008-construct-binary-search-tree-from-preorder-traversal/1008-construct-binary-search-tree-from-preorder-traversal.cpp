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
    
//      TreeNode* utility(vector<int>& preorder,int low,int high){
//         if(low>high){
//             return NULL;
//         }
        
//             int mid= low +(high -low)/2;
//             TreeNode* root= new TreeNode(preorder[mid]);
//             root->left=utility(preorder,low,mid-1);
//             root->right=utility(preorder,mid +1, high);
        
//         return root;
//     }
    
    
   TreeNode* solve(vector<int>& preorder,int &ind,int up){
       
       if(ind==preorder.size() || preorder[ind]>up)
           return NULL;
       TreeNode* root = new TreeNode(preorder[ind++]);
       root->left= solve(preorder,ind,root->val);
       root->right = solve(preorder,ind,up);
       return root;
        
    }
        
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //TreeNode* root =  new TreeNode(preordeer[0]);
        // sort(preorder.begin(),preorder.end());
        // TreeNode* root=utility(preorder,0,preorder.size()-1);
        // return root;
        int ind=0;
        return solve(preorder,ind,INT_MAX);
        
       
        
    }
};