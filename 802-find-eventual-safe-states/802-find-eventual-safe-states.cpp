class Solution {
public:
    
    bool dfs(int node, vector<int> adj[], vector<int> &vis,vector<int> &dvis,vector<int>& ans){
        
        
        vis[node]=1;
        dvis[node]=1;
     
        for(auto it: adj[node]){
            
            if(!vis[it]){
                 if( dfs(it,adj,vis,dvis,ans))
                     return ans [node]=true;
            }
            else if( vis[it] && dvis[it])
                return ans[node]=true;
            
        }
        dvis[node]=0;
        return false; ;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
     
        }
        
        vector<int> vis(n,0);
       vector<int> ans(n,0);
        vector<int> dvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,adj,vis,dvis,ans);
                    
            }
        }
       vector<int> res;
     for(int i=0;i<n;i++){
         if(ans[i]==0)
             res.push_back(i);
     }
        
        
        return res;
    }
};