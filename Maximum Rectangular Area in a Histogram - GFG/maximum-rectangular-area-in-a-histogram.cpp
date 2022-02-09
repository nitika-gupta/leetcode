// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<pair<long long  ,long long>> st;
        vector<long long> v;
        for(int i=n-1;i>=0;i--){
            if(st.empty())
                v.push_back(n);
            else if(!st.empty() && st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first >=arr[i]){
                while(!st.empty() && st.top().first>= arr[i]){
                    st.pop();
                    
                }
                if(st.empty())
                    v.push_back(n);
                else
                    v.push_back(st.top().second);
            }
            
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        
        stack<pair<long long,long long>> s;
        vector<long long> v1;
        for(int i=0;i<n;i++){
            if(s.empty())
                v1.push_back(-1);
            else if(!st.empty() && s.top().first<arr[i]){
                v1.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first>= arr[i]){
                while(!s.empty() && s.top().first>= arr[i]){
                    s.pop();
                    
                }
                if(s.empty())
                    v1.push_back(-1);
                else
                    v1.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
        }
        
       /* for(int i=0;i<n;i++){
            cout<<"right :";
            cout<<v[i];
        }
         for(int i=0;i<n;i++){
            cout<<"left :";
            cout<<v1[i];
        }*/
        
        vector<long long> width(n);
        vector<long long> area(n);
        long long max=INT_MIN;
        for(int i=0;i<n;i++){
            width[i]=v[i]-v1[i]-1;
            area[i]=arr[i]*width[i];
            if(max<area[i])
            max=area[i];
        }
        return max;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends