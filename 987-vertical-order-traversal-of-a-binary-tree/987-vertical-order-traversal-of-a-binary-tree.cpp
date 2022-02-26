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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                
                TreeNode* temp=q.front().first;
                int row=q.front().second.first;
                int col=q.front().second.second;
                q.pop();
                mp[row][col].insert(temp->val);
                
                if(temp->left!=NULL)
                    q.push({temp->left,{row-1,col+1}});
                if(temp->right!=NULL)
                    q.push({temp->right,{row+1,col+1}});
                
            }
        }
       
      
        
      for(auto p: mp){
          vector<int> col;
          for(auto it:p.second)
              col.insert(col.end(),it.second.begin(),it.second.end());
          res.push_back(col);
      }
       return res;
                
    }
};