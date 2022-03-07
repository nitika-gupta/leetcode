// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    int conv(string s1){
        int x=0;
        for(int i=0;i<s1.length();i++){
            x= x*10 +(s1[i]-'0');
            
        }
        return x;
    }
        int isValid(string s) {
            // code here
            
            int a,b,c,d;
            string s1="";
            int count=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='.'){
                      if(s1=="" || s1.length()>3)
                        return 0;
                    if(count==0){
                      
                        a=conv(s1);
                        string x=to_string(a);
                        if(s1.length() !=x.length())
                        return 0;
                    }
                    else if(count==1){
                        b=conv(s1);
                        string x=to_string(b);
                        if(s1.length() !=x.length())
                        return 0;
                    
                    }
                    else if(count==2){
                        c=conv(s1);
                        string x=to_string(c);
                        if(s1.length() !=x.length())
                        return 0;
                    }
                     
                   // cout<<s1<<" ";
                    count++;
                    s1="";
                }
                else
                s1+=s[i];
            }
            if(count==3){
                        d=conv(s1);
                        string x=to_string(d);
                        if(s1.length() !=x.length())
                        return 0;
                    }
                 //   cout<<s1;
                 if(count>3)
                    return 0;
            if(a<0 || a>255 || b<0 ||b>255 ||c<0 ||c>255 ||d<0|| d>255){
                return 0;
            }
            return 1;
           
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends