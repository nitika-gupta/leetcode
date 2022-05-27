// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int i, vector<int> &vis,vector<int> adj[]){
       // cout<<i<<" ";
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int v=0;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	       dfs(i,vis,adj);
	       v=i;
	        }
	       
	    }
	       
	     fill(vis.begin(),vis.end(),0);
	     dfs(v,vis,adj);
	     for(int i=0;i<V;i++)
	        if(vis[i]==0)
	            return -1;
	    
	    return v;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends