// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int price[], int n)
    {
      //Your code here
      vector<int> l;
      vector<int> r;
      
       stack<int> s1;
       stack<int> s2;
      
       
       for(int i=0;i<n;i++){
           if(s1.size()==0){
               l.push_back(0);
               
           }
           else if(s1.size()>0 && s1.top()<price[i]){
               l.push_back(s1.top());
           }
          else  if(s1.size()>0 && s1.top()>=price[i]){
               
           
           while(!s1.empty() && s1.top()>=price[i]){
              
               s1.pop();
           }
           if(s1.size()==0){
               l.push_back(0);
           }
           else{
               l.push_back(s1.top());
               
           }
           
          
           }
           s1.push(price[i]);
       }
       
       for(int i=n-1;i>=0;i--){
           if(s2.size()==0){
               r.push_back(0);
               
           }
           else if(s2.size()>0 && s2.top()<price[i]){
               r.push_back(s2.top());
           }
          else  if(s2.size()>0 && s2.top()>=price[i]){
               
           
           while(!s2.empty() && s2.top()>=price[i]){
              
               s2.pop();
           }
           if(s2.size()==0){
               r.push_back(0);
           }
           else{
               r.push_back(s2.top());
               
           }
           
          
           }
           s2.push(price[i]);
       }
       reverse(r.begin(),r.end());
   
       
      int max=INT_MIN;
       for(int i=0;i<n;i++){
           if(max<abs(l[i]-r[i]))
           max=abs(l[i]-r[i]);
       }
       
       return max;
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
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends