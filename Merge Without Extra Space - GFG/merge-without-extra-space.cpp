// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here if(n<m)
            int i=n-1;
            int j=0;
            
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
             
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            // for( int i=0;i<n-1;i++)
            //  {
            //     if(arr1[i]>arr2[0])
            //     {
            //         if(arr2[0]<arr2[1])
            //         {
            //             swap(arr1[i],arr2[0]);
            //         }
            //         else if(arr2[0]>arr2[1])
            //         {
                        
            //             swap(arr2[0],arr2[1]);
            //             if(arr1[i]>arr2[0])
            //             {
            //                 swap(arr1[i],arr2[0]);
            //             }
            //         }
            //     }
            // }
            // //sort(arr1,arr1+n);
            // sort(arr2,arr2+m);
            // if(arr1[n-1]>arr2[0])
            // {
                
            //     swap(arr1[n-1],arr2[0]);
            // }
            // sort(arr1,arr1+n);
            // sort(arr2,arr2+m);
            
         }

        
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends