// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int toggleBits(int n , int l , int r) {
        // code here
        int a=1;
        int pos=1;
        
        while(true){
            if(pos>=l && pos<=r){
                n=n^a;
            }
            a=a<<1;
            pos++;
            if(pos>r)
            break;
        }
        return n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends