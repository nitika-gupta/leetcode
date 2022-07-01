class Solution {
public:
    bool isValid(int x,int y, vector<vector<char>> & board,char val){
        
        
        for(int i=0;i<board.size();i++){
            if(board[x][i]==val)
                return false;
        }
        
        for(int j=0;j<board[0].size();j++){
            if(board[j][y]==val)
                return false;
        }
        
        int si=x/3 *3;
        int sj=y/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[si+i][sj+j]==val)
                    return false;
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>& board){
        if(i==board.size())
            return true;
        if(j==9) return solve( i+1, 0,board);
       
        if(board[i][j]!='.')
        {
            return solve(i,j+1,board);
        }
       
      
        for(char c='1';c<='9';c++){
            
            if(isValid(i,j,board,c)){
                board[i][j]=c;
                
                if(solve(i,j+1,board)==true)
                    return true;
                board[i][j]='.';
                }
             
            }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(0,0, board);
    }
};