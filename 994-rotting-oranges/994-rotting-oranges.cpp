class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int qs=0;
        int orange=0;
        queue<pair<int,int>> q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    orange++;
                if(grid[i][j]==2){
                    orange++;
                    q.push({i,j});
                    qs++;
                }
            }
         }
        if(orange==0)
            return 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
                
            while(!q.empty()){
                       int len=q.size();
                        count++;
                        for(int k=0;k<len;k++){
                            int r=q.front().first;
                            int c=q.front().second;
                            q.pop();
                            if(r-1>=0 &&grid[r-1][c]==1 ){
                                grid[r-1][c]=2;
                               
                                q.push({r-1,c});
                                qs++;
                            }
                            
                            if(r+1<=n-1 &&grid[r+1][c]==1){
                                grid[r+1][c]=2;
                                
                                q.push({r+1,c});
                                qs++;
                            }
                            if(c-1>=0 &&grid[r][c-1]==1 ){
                                grid[r][c-1]=2;
                                
                                q.push({r,c-1});
                                qs++;
                            }
                            if(c+1<=m-1 &&grid[r][c+1]==1 ){
                                grid[r][c+1]=2;
                              
                                q.push({r,c+1});
                                qs++;
                            }
                    }
                }
       
        if(qs==orange)
            return count-1;
        return -1;
        
    
    }
};