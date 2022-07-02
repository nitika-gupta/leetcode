// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int  exists(vector<vector<int>> &matrix, int r, int c,int mid){
        int count=0;
        
        for(int i=0;i<r;i++){
            int s=0;
            int e=c-1;
            while(s<=e){
                int m= s+ (e-s)/2;
                if(matrix[i][m]<=mid){
                    
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
            count+= s;
        }
        
        return count;
        
        
    }
    
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        int start=INT_MAX;
        int end=INT_MIN;
        for(int j=0;j<r;j++){
            start=min(start, matrix[j][0]);
            end=max(end,matrix[j][c-1]);
        }
        int res=-1;
        
        while(start<=end){
            int mid= start + (end-start)/2;
            //cout<<mid<<" ";
            int count=exists(matrix,r,c,mid);
            //cout<<count<<" ";
            
                if(count>=(r*c+1)/2)
                    {
                        res=mid;
                        //return res;
                        end=mid-1;
                    }
                    // else if(count>(r*c+1)/2)
                    //     end=mid-1;
                
               
                else 
                    start= mid+1;
                
            }
            
            
        
        return res;
     
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends