class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums2.size());
        stack<int> st;
        st.push(-1);
        int n=nums2.size()-1;
        res[n]=-1;
        st.push(nums2[n]);
        for(int i=n-1;i>=0;i--){
            if(nums2[i]<=st.top()){
                res[i]=st.top();
                st.push(nums2[i]);
                
            }
            else{
                while(!st.empty() && st.top()!=-1){
                    st.pop();
                    if(nums2[i]<st.top()){
                        res[i]=st.top();
                        st.push(nums2[i]);
                        break;
                    }
                }
                if(st.top()==-1){
                    res[i]=-1;
                    st.push(nums2[i]);
                }
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=res[i];
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
    }
};