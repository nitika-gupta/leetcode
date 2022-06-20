// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length()!=str2.length())
        return false;
        
        if(str1.length()<2){
            
        return str1==str2;
        }
        int n= str1.length();
        string s1="";
        s1+= str1.substr(2,n) + str1.substr(0,2);
        
        if(s1==str2)
            return true;
        
        string s2="";
        s2+=str1.substr(n-2,n) + str1.substr(0,n-2);
        if(s2==str2)
            return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends