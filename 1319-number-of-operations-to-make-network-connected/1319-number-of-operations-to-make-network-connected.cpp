class Solution {
public:
    
    void dfs(vector<int>adj[],vector<int>& vis,int index){
        vis[index]=1;
        for(auto it:adj[index]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=0;
        
        vector<int> adj[n+1];
        
        vector<int> vis(n,0);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }    
        //cout<<"edges"<<edges<<" ";
        int comp=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(adj,vis,i);
            }
        }
        
        if(edges<n-1){
            return -1;
        }
        int red= edges-((n-1)-(comp-1));
        if(red<comp-1)
            return -1;
        return comp-1;
    }
};