// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int m) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        map<vector<int>,int> mp;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int x=arr[i] +arr[j];
                int k=j+1;
                int l=arr.size()-1;
                while(k<l){
                    if(x +arr[k] + arr[l] ==m){
                        mp.insert({{arr[i],arr[j],arr[k],arr[l]},1});
                        k++;
                        l--;
                    }
                    else if(x + arr[k] + arr[l]>m){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        
        vector<vector<int>> res;
        for(auto it: mp){
            res.push_back(it.first);
        }
        return res;
            
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends