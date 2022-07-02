// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int A[],int k,int mx,int n){
    int student=1;
    int sum=0;
    
    for(int i=0;i<n;i++){
        
        if(sum+A[i]>mx){
            student++;
            sum=A[i];
        }
        else{
            sum+=A[i];
        }
        
       
    }
     if(student>k)
            return false;
    return true;
    //return student<=k;
    
}
    int findPages(int A[], int N, int k) 
    {
        //code here
        if(N<k)
        return -1;
           int start=0;
    int sum=0;
    int x=INT_MIN;
    for(int i=0;i<N;i++){
        sum+=A[i];
        x=max(x,A[i]);
    }
    start=x;
    int end=sum;
    int res=0;
    while(start<=end){
        int mid= start + (end-start)/2;
        
        if(isValid(A,k,mid,N)){
            res=mid;
            end=mid-1;
        }
        else start= mid+1;
    }
    return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends