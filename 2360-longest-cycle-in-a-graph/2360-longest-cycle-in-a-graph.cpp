class Solution {
public:
     bool dfs(int i, vector<int> &vis,vector<int> &dfsv,vector<int> adj[], int &count,vector<int> &dist){
        vis[i]=1;
        dfsv[i]=1;
       if(dist[i]==-1){
            dist[i]=count;
            count++;
       }
        for(auto it: adj[i]){
           
            
            if(!vis[it]){
                
                
                if(dfs(it,vis,dfsv,adj,count,dist)){
                      dfsv[i] = 0; 
                    dist[i]=-1;
                    
                    return true;
                }
            }
            else if(dfsv[it]==1){
                 
                     count =count -dist[it] ;
                     
                     dfsv[i] = 0; 
                     dist[i]=-1; 
                     return true;
            }
            
        }
         
         dfsv[i] = 0; 
        dist[i]=-1;
        
        return false;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
       
        vector<int> vis(n,0);
        vector<int> dfsv(n,0);
        vector<int> dist(n,-1);
        int res =INT_MIN;
        for(int i=0;i<n;i++){
            if(!vis[i] ){
                int count = 0;
                
                if(dfs(i,vis,dfsv,adj,count,dist)){
                   
                    res = max(res, count);
                }
                
            }
        }
        if(res == INT_MIN)
            return -1;
        return res;
        
    }
};