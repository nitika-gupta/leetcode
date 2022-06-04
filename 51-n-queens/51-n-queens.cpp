class Solution {
public:
    bool safe(int col,int row,vector<string>& board,int n){
        int r=row,c=col;
        
        while(c>=0){
            if(board[r][c]=='Q')
                return false;
            c--;
        }
        c=col;
        
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')
                return false;
            c--;
            r--;
        }
        
        r=row;
        c=col;
        
        while(r<=n-1 && c>=0){
            if(board[r][c]=='Q')
                return false;
            c--;
            r++;
        }
        return true;
    }
   void solve(int col,vector<string> &board,vector<vector<string>>& ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
       for(int i=0;i<n;i++){
           if(safe(col,i,board,n)){
               board[i][col]='Q';
               solve(col+1,board,ans,n);
               board[i][col]='.';
           }
       }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};