// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int N){
	    //code
	    int l=0;
	    int h=N-1;
	    
	    while(l<=h){
	        int mid= l+ (h-l)/2;
	        
	        if((mid%2==0 && nums[mid+1]!=nums[mid]) || (mid%2==1 && nums[mid-1]!=nums[mid]) ){
	           
	             h=mid-1;
	        }
	        
	        else{
	            l=mid+1;
	        }
	    }
	    return nums[l];
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends