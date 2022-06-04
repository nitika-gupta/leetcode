// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
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
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<int> temp;
        solve(0,board,ans,n,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends