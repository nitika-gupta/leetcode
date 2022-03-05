// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        long long m=1e9+7;
        long long int prev2=0;
        long long int prev=1;
         long long int cur;
        for(int i=2;i<=n;i++){
            cur=(prev+prev2)%m;
            prev2=(prev)%m;
            prev=(cur)%m;
        }
        return cur%m;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends