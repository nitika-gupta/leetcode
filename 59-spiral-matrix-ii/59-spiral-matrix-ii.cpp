class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n,vector<int>(n));
        
        int top=0;
        int left=0;
        int right=n-1;
        int down=n-1;
        
        int count=1;
        while(top<=down){
            
            int i=top;
            int j;
            for( j=left;j<=right;j++){
                //count++;
                grid[i][j]=count++;
            }
            top++;
            
            j=right;
            
            for(i=top;i<= down;i++){
                //count++;
                grid[i][j]=count++;
            }
            right--;
            i=down;
            for(j=right;j>=left;j--){
                //count++;
                grid[i][j]=count++;
                
            }
            down--;
            j=left;
            for(i=down;i>=top;i--){
               // count++;
                grid[i][j]= count++;
            }
            left++;
            
        }
        return grid;
    }
};