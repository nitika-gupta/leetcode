class Solution {
public:
    
    bool safe(int row,int col,vector<vector<int>>& board,int n){
        int r=row,c=col;
        
        while(c>=0){
            if(board[r][c]==1)
                return false;
            c--;
        }
        c=col;
        
        while(r>=0 && c>=0){
            if(board[r][c]==1)
                return false;
            c--;
            r--;
        }
        
        r=row;
        c=col;
        
        while(r<=n-1 && c>=0){
            if(board[r][c]==1)
                return false;
            c--;
            r++;
        }
        return true;
    }
    
    void solve(int col,vector<vector<int>> & board,vector<vector<int>> &ans,int n,vector<int> & temp){
        if(col==n){
            ans.push_back(temp);
            //cout<<"hi "
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(i,col,board,n)){
                //cout<<i<<" ";
                temp.push_back(i+1);
                board[i][col]=1;
                solve(col+1,board,ans,n,temp);
                temp.pop_back();
                board[i][col]=0;
                
            }
        }
    }
    int totalNQueens(int n) {
        
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<int> temp;
        solve(0,board,ans,n,temp);
        map<vector<int>,int> mp;
        for(auto it :ans){
            mp[it]++;
        }
        return mp.size();
    }
};