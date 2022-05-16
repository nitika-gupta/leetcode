class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
         
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r-1>=0){
                if(dp[r][c]+1<dp[r-1][c]){
                    dp[r-1][c]=dp[r][c] +1 ;
                    q.push({r-1,c});
                }
            }
            if(c-1>=0){
                if(dp[r][c]+1<dp[r][c-1]){
                    dp[r][c-1]=dp[r][c]+1;
                    q.push({r,c-1});
                }
                
            }
             if(c+1<m){
                if(dp[r][c]+1<dp[r][c+1]){
                    dp[r][c+1]=dp[r][c]+1;
                    q.push({r,c+1});
                }
                
            }
             if(r+1<n){
                if(dp[r][c]+1<dp[r+1][c]){
                    dp[r+1][c]=dp[r][c]+1;
                    q.push({r+1,c});
                }
                
            }
            
            
        }
        
                    
                
                
        return dp;
    }
};