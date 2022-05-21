class Solution {
public:
    
    int dfs(int id,vector<int>& manager, vector<int>& info,vector<int> adj[]){
        int ans=INT_MIN;
        for(auto it: adj[id]){
            ans=max(ans,info[id] + dfs(it,manager,info,adj));
           cout<<info[id]<<" ";
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
        
    }
    int numOfMinutes(int n, int hid, vector<int>& manager, vector<int>& info) {
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            if(i!=hid)
            adj[manager[i]].push_back(i);
            
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        // }
        
        return dfs(hid,manager,info,adj);
        
    }
};