/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void depth(Node* root,int dep,int & res){
        if(root->children.size()==0){
            
            res = max(dep,res);
        }
        
        for(int i=0;i<root->children.size();i++){
            cout<<dep<<endl;
             depth(root->children[i], dep+1,res);
        }
       
    }
    
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int dep=1;
        int res = INT_MIN;
       depth(root,dep,res);
        return res;
    }
};