class Solution {
public:
    void dfs(int node,int parent, int &time, vector<int> adj[],vector<int> & tin,vector<int> & vis,vector<int> & low,vector<vector<int>> & ans){
        vis[node]=1;
        tin[node]=low[node]=time++;
        int child=0;
        
        for(auto it : adj[node]){
           if(it == parent) continue;
            
            if(!vis[it]){
                
                dfs(it,node,time,adj,tin,vis,low,ans);
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node] ){
                    vector<int> a;
                    cout<<node;
                    a.push_back(node);
                    a.push_back(it);
                    ans.push_back(a);
                }
                    
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        
        vector<vector<int>> ans;
        int time=0;
        
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,time,adj,tin,vis,low,ans);
            }
        }
        return ans;
    }
};