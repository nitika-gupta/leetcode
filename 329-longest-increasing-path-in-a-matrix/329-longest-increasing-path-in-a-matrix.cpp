class Solution {
public:
    int dfs(int i,int j , vector<vector<int>>& matrix,int c,int &maxp, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=matrix.size()|| j>=matrix[0].size()  )
            return c;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int x=0,y=0,z=0,w=0;
      
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j] ){
           
            //cout<<c<<" ";
            maxp=max(c+1,maxp);
            cout<<maxp<<" ";
           x=dfs(i-1,j,matrix,c+1,maxp,dp);
      
        }
         if(j-1>=0 && matrix[i][j]<matrix[i][j-1] ){

            maxp=max(c+1,maxp);
            y =dfs(i,j-1,matrix,c+1,maxp,dp);
   
        }
         if(i+1<matrix.size() && matrix[i][j]<matrix[i+1][j]){
      
            maxp=max(c+1,maxp);
           z= dfs(i+1,j,matrix,c+1,maxp,dp);
    
        }
         if(j+1<matrix[0].size() && matrix[i][j]<matrix[i][j+1] ){

            maxp=max(c+1,maxp);
            w=dfs(i,j+1,matrix,c+1,maxp,dp);
     
        }
        cout<<maxp<<" ";
        return dp[i][j]=1 + max({x,y,z,w});
        
        
        
}
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int maxp=1;
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              
                maxp=max(maxp,dfs(i,j,matrix,1,maxp,dp));
            }
        }
        return maxp;
    }
};