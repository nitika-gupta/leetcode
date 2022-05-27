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
	    
	    for(int i=0;i<V;i++){
	       vector<int> vis(V,0);
	       dfs(i,vis,adj);
	       int flag=0;
	       
	       for(int j=0;j<V;j++){
	           if(vis[j]==0)
	           flag=1;
	         //  cout<<vis[j]<<" ";
	       }
	      
	       if(flag==0)
	        return i;
	    }
	    return -1;
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