class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n= board.size();
        int m = board[0].size();
        vector<vector<int>> temp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j]=board[i][j];
            }
        }
        for(int i=0;i<board.size();i++){
             
            for(int j=0;j<board[0].size();j++){
                
               int sum=0;
                
                // if(i-1>=0 && j-1>=0)
                //     sum+=board[i-1][j-1];
                
                if(i+1<=n-1 && j<=m-1)
                    sum+=board[i+1][j];
                
                if(i-1>=0 && j-1>=0)
                    sum+=board[i-1][j-1];
                
                if(i+1<=n-1 && j-1>=0)
                    sum+=board[i+1][j-1];
                
                
                if(i+1<=n-1 && j+1<=m-1)
                    sum+=board[i+1][j+1];
                
                if(i<=n-1 && j+1<=m-1)
                    sum+=board[i][j+1];
                
                if(i-1>=0 &&j+1<=m-1)
                    sum+=board[i-1][j+1];
                
                if(i>=0 && j-1>=0)
                    sum+=board[i][j-1];
                if(i-1>=0 && j>=0){
                    sum+=board[i-1][j];
                }
                cout<<sum<<endl;
                
                 if(temp[i][j]==1 && sum<2)
                temp[i][j]=0;
           
            else if(temp[i][j]==1 && sum>3)
                temp[i][j]=0;
            else if(temp[i][j]==0 && sum==3)
                temp[i][j]=1;
                else if(temp[i][j]==1 && (sum==2 || sum==3)){
                temp[i][j]=1;
            }
             
            }
           
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=temp[i][j];
            }
        }
        
    }
};