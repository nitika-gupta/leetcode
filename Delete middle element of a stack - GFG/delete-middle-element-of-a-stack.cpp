// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int> & s,int mid){
        if(s.size()==mid){
            s.pop();
             return;
        }
       
        int temp=s.top();
        s.pop();
     solve(s,mid);
     s.push(temp);
     return;
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(s.size()==0|| s.size()==1)
        return;
        int mid=ceil(s.size()/2.0);
        solve(s,mid);
        return;
    }
};





// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends