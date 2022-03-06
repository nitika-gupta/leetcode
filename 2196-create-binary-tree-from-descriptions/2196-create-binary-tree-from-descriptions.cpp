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
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        unordered_map<int,TreeNode*> get;
        unordered_map<int,bool> ischild;
        
        for(auto &v: a){
            
            if(get.count(v[0])==0){
                TreeNode* par=new TreeNode(v[0]);
                get[v[0]]=par;
            }
            if(get.count(v[1])==0){
                TreeNode* child=new TreeNode(v[1]);
                get[v[1]]=child;
                
            }
            
            if(v[2]==1){
                get[v[0]]->left=get[v[1]];
            }
            else
                get[v[0]]->right=get[v[1]];
            ischild[v[1]]=true;
        }
        
        
        TreeNode* ans=NULL;
        for(auto &v:a){
            if(ischild[v[0]]!=true){
                ans=get[v[0]];
            }
            
        }
        return ans;
        
        
    }
};