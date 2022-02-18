// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> res;
        priority_queue<int,vector<int>, greater<int>> heap;
        for(int i=0;i<n;i++){
            heap.push(arr[i]);
            if(heap.size()>k)
                heap.pop();
            if(heap.size()==k){
                res.push_back(heap.top());
                
            }
            else if(heap.size()<k){
                res.push_back(-1);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends