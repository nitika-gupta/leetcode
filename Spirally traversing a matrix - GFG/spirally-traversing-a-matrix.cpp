// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int row=0,col=0;
        int count=0;
        vector<int> res;
        int right=c-1,down=r-1,left=0,top=0;
        while(count< r*c &&  top<=down  ||  left<=right){
            if(count<r*c)
            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
                count++;
            }
            top++;
            if(count<r*c)
            for(int i=top;i<=down;i++){
                res.push_back(matrix[i][right]);
                count++;
            }
            right--;
            if(count<r*c)
            for(int i=right;i>=left;i--){
                res.push_back(matrix[down][i]);
                count++;
            }
            down--;
            if(count<r*c)
            for(int i=down;i>=top;i--){
                res.push_back(matrix[i][left]);
                count++;
            }
            left++;
            
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends