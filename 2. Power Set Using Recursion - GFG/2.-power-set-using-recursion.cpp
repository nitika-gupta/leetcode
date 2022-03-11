// { Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


//Function to return the lexicographically sorted power-set of the string.

void solve(string in,string ot,vector<string>& res,int ind){
    if(ind>=in.size()){
        res.push_back(ot);
        return;
    }
    solve(in,ot,res,ind+1);
    solve(in,ot+in[ind],res,ind+1);
   
    
}
vector <string> powerSet(string s)
{
   //Your code here
   vector<string> res;
   solve(s,"",res,0);
   return res;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;//testcases
    while(T--)
    {
        string s;
        cin>>s;//input string
        
        //calling powerSet() function
        vector<string> ans = powerSet(s);
        
        //sorting the result of the powerSet() function
        sort(ans.begin(),ans.end());
        
        //printing the result
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends