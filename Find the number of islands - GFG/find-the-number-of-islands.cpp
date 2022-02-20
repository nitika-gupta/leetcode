// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int r,int c,int n,int m){
        
        
        if(r<0 || r>=n || c<0 || c>=m ){
            return;
        }
        if(grid[r][c]=='0' || vis[r][c])
            return;
        
        vis[r][c]=1;
        
        dfs(grid,vis,r-1,c,n,m);
        dfs(grid,vis,r+1,c,n,m);
        dfs(grid,vis,r,c-1,n,m);
        dfs(grid,vis,r,c+1,n,m);
        dfs(grid,vis,r+1,c-1,n,m);
        dfs(grid,vis,r+1,c+1,n,m);
        dfs(grid,vis,r-1,c-1,n,m);
        dfs(grid,vis,r-1,c+1,n,m);
    
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    count++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends