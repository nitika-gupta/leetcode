// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> mp;
       
        int i=0;
        int j=0;
        vector<int> res;
        while(j<n){
            if(j-i+1<k){
                mp[A[j]]++;
                
                j++;
            }
           
            else if(j-i +1==k) {
                mp[A[j]]++;
                
                
                
                res.push_back(mp.size());
                mp[A[i]]--;
                if(mp[A[i]]==0){
                    mp.erase(A[i]);
                }
                
                
                  
            i++;
            j++;
            }
            
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends