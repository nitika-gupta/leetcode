/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        root->next=NULL;
        
        while(!q.empty()){
            int n =q.size();
            vector<Node*> v;
            for(int i=0;i<n;i++){
                Node* node= q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    v.push_back(node->left);
                }
                if(node->right){
                    q.push(node->right);
                    v.push_back(node->right);
                }
            }
            // for(int i=0;i<v.size();i++){
            //     cout<<v[i]->val<<" ";
            // }
            //cout<<endl;
            for( int i=v.size()-1;i>=0;i--){
                Node * temp=v[i];
                if(i==v.size()-1){
                    temp->next=NULL;
                }
                else{
                    temp->next=v[i+1];
                }
            }
        }
        return root;
    }
};