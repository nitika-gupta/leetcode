class Solution {
public:
// //     void f(int r,int c,vector<vector<int>>& grid,int & ans,int path,vector<vector<int>>& vis){
// //         if(r==grid.size() && c==grid[0].size()){
// //             if(ans>path)
// //                 ans=path;
// //             return;
// //         }
        
// //         if(r<0||c<0 || r>=grid.size()|| c>=grid[0].size() || grid[r][c]==1 || vis[r][c]==1)
// //             return;
// //         vis[r][c]=1;
// //         f(r+1,c,grid,ans,path+1,vis);
// //         f(r-1,c,grid,ans,path+1,vis);
// //         f(r,c+1,grid,ans,path+1,vis);
// //         f(r,c-1,grid,ans,path+1,vis);
// //         f(r+1,c+1,grid,ans,path+1,vis);
// //         f(r-1,c-1,grid,ans,path+1,vis);
// //         f(r-1,c+1,grid,ans,path+1,vis);
// //         f(r+1,c-1,grid,ans,path+1,vis);
// //     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        // f(0,0,grid,ans,0,vis);
        
        if(grid[0][0]==1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;
        int level=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
            int r=q.front().first;
            int c=q.front().second;
            cout<<r<<" "<< c<<" ";
            if(r==grid.size()-1 && c==grid.size()-1){
                ans=min(ans,level);
               // cout<<ans;
            }
            q.pop();
               
          //  cout<<"level"<<level<<" ";
            
            if(r+1<grid.size() && c<grid[0].size() &&!vis[r+1][c] && grid[r+1][c]==0 ){
                vis[r+1][c]=1;
                q.push({r+1,c});
                // cout<<r+1<<" "<<c<<" ";
            }
           // cout<<level<<" ";
         
            
            if(r-1>=0 && c<grid[0].size()  && !vis[r-1][c] && grid[r-1][c]==0 ){
                vis[r-1][c]=1;
                q.push({r-1,c});
               // cout<<r-1<<" "<<c<<" ";
            }
                       //   cout<<r<<" "<<c+1<<" ";
            cout<<endl;
            if(r<grid.size() && (c+1)<grid[0].size() && !vis[r][c+1] && grid[r][c+1]==0 ){
                //cout<<"???";
                vis[r][c+1]=1;
                q.push({r,c+1});
               // cout<<r<<" "<<c+1<<" ";
            }
            if(r<grid.size() && c-1>=0 && !vis[r][c-1] && grid[r][c-1]==0 ){
                vis[r][c-1]=1;
                q.push({r,c-1});
               // cout<<r<<" "<<c-1<<" ";             
            
            }
            if(r+1<grid.size() && c+1<grid[0].size() && vis[r+1][c+1]==0 && grid[r+1][c+1]!=1 ){
                vis[r+1][c+1]=1;
                q.push({r+1,c+1});
             //   cout<<r+1<<" "<<c+1<<" ";
            }
            
            if((r-1)>=0 && (c-1)>=0 && !vis[r-1][c-1] && grid[r-1][c-1]==0 ){
                vis[r-1][c-1]=1;
            
                q.push({r-1,c-1});
                // cout<<r-1<<" "<<c-1<<" ";
                                

            }
            if((r-1)>=0 && (c+1)<grid[0].size() && !vis[r-1][c+1] && grid[r-1][c+1]==0 ){
                vis[r-1][c+1]=1;
                q.push({r-1,c+1});
                // cout<<r-1<<" "<<c+1<<" ";
            }
            
            if(r+1<grid.size() && c-1>=0 && !vis[r+1][c-1] && grid[r+1][c-1]==0 ){
                vis[r+1][c-1]=1;
                q.push({r+1,c-1});
                // cout<<r+1<<" "<<c-1<<" ";
            }
        }
            level++;
            
            
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
// class Solution {
// public:
//     void solve(int i,int j,int &c,int n,vector<vector<int>> &vis,vector<vector<int>>& grid,vector<int> &count)
//     {   cout<<i<<" "<<j<<" ";
//         if(n!=1 && i==n-1 && j==n-1)
//         {
//             if(c!=1)
//                 count.push_back(c);
//             return;
//         }
//         //cout<<c<<" ";
//         if(i+1<n && !vis[i+1][j] && grid[i+1][j]==0)
//         {
//             c++;
           
//             vis[i][j]=1;
//             solve(i+1,j,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
            
//         }
//         if(i+1<n && j+1<n && !vis[i+1][j+1] && grid[i+1][j+1]==0)
//         {   
//             c++;
//              cout<<c<<" ";
//             vis[i][j]=1;
//             solve(i+1,j+1,c,n,vis,grid,count);
//            vis[i][j]=0;
//            c--;
//         }if(j+1<n && !vis[i][j+1] && grid[i][j+1]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i,j+1,c,n,vis,grid,count);
//            vis[i][j]=0;
//             c--;
//         }
//         if(i-1>0 && j+1<n && !vis[i-1][j+1] && grid[i-1][j+1]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i-1,j+1,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
//         }
//         if(i-1>0 && !vis[i-1][j] && grid[i-1][j]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i-1,j,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
//         }
//         if(i-1>=0 && j-1>=0 && !vis[i-1][j-1] && grid[i-1][j-1]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i-1,j-1,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
//         }
//         if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i,j-1,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
//         }
//         if(i+1<n  && j-1>=0 && !vis[i+1][j-1] && grid[i+1][j-1]==0)
//         {
//             c++;
//             vis[i][j]=1;
//             solve(i+1,j-1,c,n,vis,grid,count);
//             vis[i][j]=0;
//             c--;
//         }
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
//     {
//         int n=grid.size();
        
//         if(n==1)
//         {
//             if(grid[0][0]==0)
//                 return 1;
//             return -1;
//         }
//         if(grid[n-1][n-1]==1)
//         {
//             return -1;
//         }
//         int c=-1;
//         vector<vector<int>>vis(n,vector<int>(n,0));
//         vector<int>count;
//         if(grid[0][0]==0)
//         {
//             c=1;
//             solve(0,0,c,n,vis,grid,count);
//             c=count[0];
//             for(int i=1;i<n;i++)
//             {
//                 c=min(c,count[i]);
//             }
           
//         }
//          return c;
//     }
// };