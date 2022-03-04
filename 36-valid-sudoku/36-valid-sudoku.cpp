class Solution {
public:
    
    bool val(vector<vector<char>>& board,int x,int y,int r,int c) {
        unordered_map<char,int> mp;
        for(int i=x;i<r;i++){
            for(int j=y;j<c;j++){
                if(board[i][j]!='.' ){
            
                    if(mp.find(board[i][j])==mp.end())
                        mp[board[i][j]]++;
                    else{
                        return false;
                    }
                }
                }
            }
                
            
        
        return true;
        
    }
        bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_map<char,int> mp;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.' ){
                    if(mp.find(board[i][j])==mp.end())
                        mp[board[i][j]]++;
                    else{
                        return false;
                    }
                }
            }
        }
        
        for(int i=0;i<board[0].size();i++){
            unordered_map<char,int> mp;
            for(int j=0;j<board.size();j++){
                if(board[j][i]!='.' ){
                    if(mp.find(board[j][i])==mp.end())
                        mp[board[j][i]]++;
                    else{
                        return false;
                    }
                }
            }
        }
    
    if( (val(board,0,0,3,3) && val(board,0,3,3,6) && val(board,0,6,3,9) &&
       val(board,3,0,6,3) && val(board,3,3,6,6) && val(board,3,6,6,9) &&
       val(board,6,0,9,3) && val(board,6,3,9,6) &&val(board,6,6,9,9)) ==false)
        return false;
        
        
    
            
        
        return true;
    }
};