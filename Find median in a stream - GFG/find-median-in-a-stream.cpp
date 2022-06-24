// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> pq1;
    priority_queue<int,vector<int>, greater<int>> pq2;
    
    
    void insertHeap(int &num)
    {
          if(pq1.empty() || pq1.top()>num){
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }
        
      balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
          if(pq2.size() >pq1.size()+1){
            pq1.push(pq2.top());
            pq2.pop();
            
        }
        else if(pq2.size()+1 <pq1.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
         double median;
        if(pq2.size()==pq1.size()){
            int a= pq1.top();
            int b= pq2.top();
             median= (double)((double)a+(double)b)/2.0;
        }
        else {
            if(pq2.size()<pq1.size())
                median= pq1.top();
            else{
                median= pq2.top();
            }
        }
        return median;
        
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends