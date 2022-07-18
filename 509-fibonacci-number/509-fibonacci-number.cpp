class Solution {
public:
    
    
    int helper(vector<int> & arr, int n){
        if(n<=1){
            return n;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        
        int a=helper(arr,n-1);
        int b=helper(arr,n-2);
        arr[n]=a+b;
        return arr[n];
    }
    int fib(int n) {
        vector<int> arr(n+1,-1);
        int ans= helper(arr,n);
        return ans;
    }
};