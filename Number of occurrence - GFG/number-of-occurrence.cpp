// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int first(int arr[], int x,int n){
        int start=0;
        int end=n-1;
        int res=-1;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(arr[mid]==x){
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
	
	//function to find the last occurance
    int last(int arr[], int x,int n){
        int start=0;
        int end=n-1;
        int res=-1;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(arr[mid]==x){
                res=mid;
                start=mid+1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int f=first(arr,x,n);
	    //cout<<f;
	    int l=last(arr,x,n);
	    //cout<<l;
	    if(f == -1)
	        return 0;
	    return l-f+1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends