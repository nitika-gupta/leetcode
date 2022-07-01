// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
      bool isValid(int x,int y, int grid[N][N],int  val){
        
        
        for(int i=0;i<N;i++){
            if(grid[x][i]==val)
                return false;
        }
        
        for(int j=0;j<N;j++){
            if(grid[j][y]==val)
                return false;
        }
        
        int si=x/3 *3;
        int sj=y/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[si+i][sj+j]==val)
                    return false;
            }
        }
        return true;
    }
      bool solve(int i,int j,int grid[N][N]){
        if(i==N)
            return true;
        if(j==9) return solve( i+1, 0,grid);
       
        if(grid[i][j]!=0)
        {
            return solve(i,j+1,grid);
        }
       
      
        for(int  c=1;c<=9;c++){
            
            if(isValid(i,j,grid,c)){
                grid[i][j]=c;
                
                if(solve(i,j+1,grid)==true)
                    return true;
                grid[i][j]=0;
                }
             
            }
        
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(0,0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
         for(int row=0; row< N; row++){
            for(int col=0; col< N; col++){
                cout<<grid[row][col]<<" ";
            }
        }
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends