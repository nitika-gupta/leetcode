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
            vector<int> vec;
        int rowbegin=0; 
        int rowEnd = matrix.size()-1;
        int colBegin=0;
        int colEnd = matrix[0].size()-1;
         int count =0;
         int size=r*c;
        while(rowbegin<=rowEnd &&  colBegin<=colEnd){
            if(count< size)
            for(int i=colBegin;i<=colEnd; i++){
                vec.push_back(matrix[rowbegin][i]);
                count++;
            }
            rowbegin++;
            if(count< size)
            for(int j =rowbegin; j<=rowEnd;j++){
               // vec.push_back(matrix[colEnd][j]);
               vec.push_back(matrix[j][colEnd]);
               count++;
                //j,colend
            }
            colEnd--;
            if(count< size)
            for(int i=colEnd;i>=colBegin;i--){
                vec.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;
            if(count< size)
            for(int j=rowEnd;j>=rowbegin;j--){
                vec.push_back(matrix[j][colBegin]);
                count++;
            }
            colBegin++;
        }
        return vec;
        
       /* vector<int> vec;
        int rowbegin=0; 
        int rowEnd = matrix.size()-1;
        int colBegin=0;
        int colEnd = matrix[0].size()-1;
        
        while(rowbegin<=rowEnd && colBegin <= colEnd){
            for(int i=colBegin;i<=colEnd; i++){
                vec.push_back(matrix[i][rowbegin]);
            }
            rowbegin++;
            
            for(int j =rowbegin; j<=rowEnd;j++){
                vec.push_back(matrix[colEnd][j]);
            }
            colEnd--;
            
            for(int i=colEnd;i>=colBegin;i--){
                vec.push_back(matrix[i][rowEnd]);
            }
            rowEnd--;
            
            for(int j=rowEnd;j>=rowbegin;j--){
                vec.push_back(matrix[j][colBegin]);
            }
            colBegin++;
        }
        return vec;*/
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