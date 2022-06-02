class Solution {
public:
    
    bool cycle(int node,vector<int> adj[], vector<int>& vis, vector<int> & dvis){
        vis[node]=1;
        dvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(cycle(it,adj,vis,dvis)) return true;
            }
            else if(dvis[it]){
                return true;
            }
        }
        
        dvis[node]=0;
        return false;
    }
    void pre(int ind,vector<int> adj[],vector<int>& vi,stack<int> &st ){
        vi[ind]=1;
        for(auto it:adj[ind]){
            if(!vi[it]){
                pre(it,adj,vi,st);
            }
        }
        st.push(ind);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        
        
        
        stack<int> st;
        vector<int> adj[n];
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> dvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,adj,vis,dvis))
                    return {};
            }
        }
        vector<int> vi(n,0);
        for(int i=0;i<n;i++){
            if(!vi[i]){
                pre(i,adj,vi,st);
            }
        }
       
        vector<int> ans;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            ans.push_back(x);
        }
        
        return ans;
        
    }
};