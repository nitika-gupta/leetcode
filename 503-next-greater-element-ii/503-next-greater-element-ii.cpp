class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        long long it=2*n-1;
        stack<long long int> st;
        vector<int> res(n,-1);
        for(long long int i=it;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
                if(!st.empty() ){
                    res[i%n]=st.top();       
                     }
            st.push(nums[i%n]);
        }
        return res;
    }
};