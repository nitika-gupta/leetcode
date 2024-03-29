class Solution {
public:
//     int dfs(int i,int j , vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(i<0 || j<0 || i>=matrix.size()|| j>=matrix[0].size()  )
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int x=0,y=0,z=0,w=0;
      
//         if(i-1>=0 && matrix[i][j]<matrix[i-1][j] ){
      
//            x=dfs(i-1,j,matrix,dp);
      
//         }
//          if(j-1>=0 && matrix[i][j]<matrix[i][j-1] ){

//             y =dfs(i,j-1,matrix,dp);
   
//         }
//          if(i+1<matrix.size() && matrix[i][j]<matrix[i+1][j]){
      
//            z= dfs(i+1,j,matrix,dp);
    
//         }
//          if(j+1<matrix[0].size() && matrix[i][j]<matrix[i][j+1] ){

//             w=dfs(i,j+1,matrix,dp);
     
//         }
      
//         return dp[i][j]=1 + max({x,y,z,w});
        
        
        
// }
    
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
//         int maxp=1;
//         vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size(),0));
//         vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
              
//                 maxp=max(maxp,dfs(i,j,matrix,dp));
//             }
//         }
//         for(int i=0;i<dp.size();i++){
//             for(int j=0;j<dp[0].size();j++){
//                 cout<<dp[i][j];
//             }
//             cout<<endl;
//         }
        
//         return maxp;
//     }
    
    int sdf(int i,int j , vector<vector<int>>& matrix, int temp,vector<vector<int>>& dp)
    {
        if(i<0|| j<0  || i>=matrix.size() || j>=matrix[0].size() || temp>=matrix[i][j])
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int x = 1 + sdf(i,j-1,matrix,matrix[i][j],dp);
         int y = 1 + sdf(i-1,j,matrix,matrix[i][j],dp);
         int p = 1 + sdf(i+1,j,matrix,matrix[i][j],dp);
         int q = 1 + sdf(i,j+1,matrix,matrix[i][j],dp);
        int a = INT_MIN;
        a = max(a,x);
        a = max(a,y);
        a = max(a,p);
        a = max(a,q);
        //a = max(a,matrix[i][j]);
        dp[i][j]=a;
        return a;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int cnt = -1;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
             int cnt2;
                 cnt2 = sdf(i,j,matrix,INT_MIN,dp);
             cnt = max(cnt,cnt2);   
            }
        }
        return cnt;
    }
};