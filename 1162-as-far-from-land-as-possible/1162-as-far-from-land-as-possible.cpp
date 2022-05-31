class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==n*m)
            return -1;
        
        int l=0;
        
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int r=q.front().first;
                int c=q.front().second;
                 q.pop();
                if(r-1>=0 && grid[r-1][c]==0){
                    grid[r-1][c]=1;
                    q.push({r-1,c});
                }
                
                if(r+1<=n-1 && grid[r+1][c]==0){
                    grid[r+1][c]=1;
                    q.push({r+1,c});
                }
                if(c-1>=0 && grid[r][c-1]==0){
                    grid[r][c-1]=1;
                    q.push({r,c-1});
                }
                if(c+1<=m-1 && grid[r][c+1]==0){
                    grid[r][c+1]=1;
                    q.push({r,c+1});
                }
                
                
            }
            l++;
            
            
            
        }
        return l-1;
        
    }
};