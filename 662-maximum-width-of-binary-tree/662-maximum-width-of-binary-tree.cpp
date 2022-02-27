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
    int widthOfBinaryTree(TreeNode* root) {
         if(root == NULL) return 0;
        int res = 0;
		queue<pair<TreeNode*, unsigned int>> q;        // queue<Nodes, Indexes of the Nodes> q
        q.push({root, 0});

        while(!q.empty()){
        	auto size = q.size();
			unsigned int leftNodeIdx = q.front().second;     // Here, idx can't go negative. Therefore, I've used Unsigned Int
        	unsigned int rightNodeIdx = 0;
        	while(size--){
        		auto [node, rightIdx] = q.front();	q.pop();
        		rightNodeIdx = rightIdx;

        		if(node->left != NULL) q.push({node->left, 2 * rightNodeIdx + 1});
        		if(node->right != NULL) q.push({node->right, 2 * rightNodeIdx + 2});
        	}
        	res = max(res, int(rightNodeIdx - leftNodeIdx + 1));
        }
        return res;
    }
};