// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
   //long long int count=0;
    long long int merge(long long arr[],long long  n ,long long int l,long long int m,long long int h){
        int a1=m-l+1;
        int a2=h-m;
        long long int arr1[a1];
        long long int arr2[a2];
        for(int i=0;i<a1;i++){
            arr1[i]=arr[l+i];
        }
        for(int i=0;i<a2;i++){
            arr2[i]=arr[m+1+i];
        }
        long long int i=0;
        long long int j=0;
        long long int k=l;
        long long int count=0;
        while(i<a1 &&j<a2){
            if(arr1[i]<=arr2[j]){
                arr[k]=arr1[i];
                k++;
                i++;
                            

            }
            else {
                count =count +a1-i;
                
                arr[k]=arr2[j];
                k++;
                j++;
            }
        }
        while(i<a1){
            arr[k]=arr1[i];
            i++;
            k++;
            //count++;
            
        }
        while(j<a2){
            
            arr[k]=arr2[j];
            j++;
            k++;
        }
       // cout<<count<<endl;
        return count;
    }
   long long int mergesort(long long arr[], long long  n, long long l,long long int h){
          long long count=0;
        if(l<h){
            
          
       long long int mid=( l+h)/2;
       count+= mergesort(arr,n,l,mid);
       count+= mergesort(arr,n,mid+1,h);
       count+= merge(arr,n,l,mid,h);
      
        
    }
     return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
       return mergesort(arr,n,0,n-1);
       
        
    
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends