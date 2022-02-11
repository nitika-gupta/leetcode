// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s1;
    while(k-- && !q.empty()){
        int x=q.front();
        q.pop();
        s1.push(x);
    
    }
     stack<int> s2;
     while(!q.empty()){
         int x=q.front();
         q.pop();
         s2.push(x);
     }
     
     stack<int> temp;
     while(!s2.empty()){
         temp.push(s2.top());
         s2.pop();
         
     }
     
     
     queue<int> q1;
     while(!s1.empty()){
         q1.push(s1.top());
         s1.pop();
     }
     while(!temp.empty()){
         q1.push(temp.top());
         temp.pop();
     }
     return q1;
}