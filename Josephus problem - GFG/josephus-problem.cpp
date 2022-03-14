// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
   
void solve(vector<int> & res, int k,int index){
    if(res.size()==1)
        return;
    index= (index+k-1)%res.size();
    res.erase(res.begin()+index);
    solve(res,k,index);
    return;
    
}
public:
int josephus(int n, int k)
{
   //Your code here
   vector<int> res;
   for(int i=1;i<=n;i++){
       res.push_back(i);
   }
   solve(res,k,0);
   return res[0];
}
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends