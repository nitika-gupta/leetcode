class Solution {
public:
    
//     int ans=INT_MAX;
//     void bfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& vis1){
//        // cout<<"hi";
//        // int ans =INT_MAX;
//         int level=0;
//         queue<pair<int,int>> q;
        
//         q.push({i,j});
//         vis1[i][j]=1;
//         while(!q.empty()){
            
//             int n=q.size();
//             for(int x=0;x<n;x++){
//                 int r=q.front().first;
//                 int c=q.front().second;
//                 //cout<<r<<c<<" ";
//                 q.pop();
                
//                 if(r-1>=0 && !vis1[r-1][c]){
                   
//                     if(grid[r-1][c]==-1){
                        
//                         ans=min(level,ans);
//                     }
//                     q.push({r-1,c});
//                     vis1[r-1][c]=1;
//                 }
//                   if(r+1<=grid.size()-1 && !vis1[r+1][c]){
//                       // cout<<"xx";
//                     if(grid[r+1][c]==-1){
//                         ans=min(level,ans);
//                     }
//                     q.push({r+1,c});
//                     vis1[r+1][c]=1;
//                 }
                
//                   if(c-1>=0 && !vis1[r][c-1]){
//                        //cout<<"xx";
//                     if(grid[r][c-1]==-1){
//                         ans=min(level,ans);
//                     }
//                     q.push({r,c-1});
//                     vis1[r][c-1]=1;
//                 }
//                     if(c+1<=grid[0].size()-1 && !vis1[r][c+1]){
//                        //  cout<<"xx";
//                         //cout<<r<< c+1<<" ";
//                     if(grid[r][c+1]==-1){
//                         //cout<<"xx";
//                         ans=min(level,ans);
//                     }
//                     q.push({r,c+1});
//                     vis1[r][c+1]=1;
//                 }
//             }
//             level++;
//             cout<<"l "<<level;
//         }
   // }
    void dfs(int i, int j ,vector<vector<int>>& grid, vector<vector<int>>& vis,queue<pair<int,int>> &q ){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]){
            return;
        }
       cout<<i<<j<<" ";
        
        vis[i][j]=1;
        q.push({i,j});
        dfs(i-1,j,grid,vis,q);
        dfs(i,j+1,grid,vis,q);
        dfs(i+1,j,grid,vis,q);
        dfs(i,j-1,grid,vis,q);
        
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,q);
                    i=n-1;
                    j=m-1;
                }
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<vis[i][j]<<" ";
            }
        cout<<endl;
        }
        
        
        cout<<endl;
        
        
        int ans=1e9;
        int x[]={-1,0,1,0};
        int y[]={0,-1,0,1};
        int d=0;
        while(!q.empty()){
            int len=q.size();
            
            
            for(int i=0;i<len;i++){
                auto[r ,c]=q.front();
                cout<<r<<c<<" ";
                //vis[r][c]=1;
                q.pop();
                
                for(int j=0;j<4;j++){
                    int nr=x[j]+r;
                    int nc=y[j]+c;
                    //cout<<"hi";
                    if(nr>= 0 && nr<=n-1 && nc>=0 && nc<=m-1 && grid[nr][nc]==1 && !vis[nr][nc]){
                        ans=min(d,ans);
                       // cout<<"hi";
                    }
                    if(nr>= 0 && nr<=n-1 && nc>=0 && nc<=m-1 && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
                
            }
            d++;
            cout<<endl;
            
        }
        
           
     
        return ans;
        
    }
};