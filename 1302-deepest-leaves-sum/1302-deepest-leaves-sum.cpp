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
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            int n=q.size();
            vector<int> v1;
            for(int i=0;i<n;i++){
                
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    v1.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    v1.push_back(node->right->val);
                }
            }
            if(v1.size()!=0){
                sum=0;
            for(int i=0;i<v1.size();i++){
                sum+=v1[i];
            }
            }
            
//             sum=0;
//             for(auto it:v1){
//                 sum=sum+it;
//             }
            
            
        }
        
        return sum;
    }
};