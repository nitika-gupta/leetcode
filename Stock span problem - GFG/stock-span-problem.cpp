// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>> s1;
      
       vector<int> v;
       for(int i=0;i<n;i++){
           if(s1.size()==0){
               v.push_back(-1);
               
           }
           else if(s1.size()>0 && s1.top().first>price[i]){
               v.push_back(s1.top().second);
           }
          else  if(s1.size()>0 && s1.top().first<=price[i]){
               
           
           while(!s1.empty() && s1.top().first<=price[i]){
              
               s1.pop();
           }
           if(s1.size()==0){
               v.push_back(-1);
           }
           else{
               v.push_back(s1.top().second);
               
           }
           
          
           }
           s1.push({price[i],i});
       }
       
       for(int i=0;i<v.size();i++){
           v[i]=i-v[i];
       }
       return v;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends