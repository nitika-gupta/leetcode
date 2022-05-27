// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int> adj[], vector<int> &vis,stack<int>&st){
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(i);
	}
		void dfsr(int i,vector<int> adjr[], vector<int> &vis){
	    vis[i]=1;
	    for(auto it:adjr[i]){
	        if(!vis[it]){
	            dfsr(it,adjr,vis);
	        }
	    }
	  //  st.push(i);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
                st.push(i);
            }
        }
        
        vector<int> adjr[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjr[it].push_back(i);
            }
        }
        fill(vis.begin(),vis.end(),0);
        int c=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                c++;
                dfsr(i,adjr,vis);
            }
        }
        return c;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends