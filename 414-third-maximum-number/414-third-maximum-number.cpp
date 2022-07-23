class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            while(st.size()>3){
                st.erase(st.begin());
            }
        }
        return (st.size() == 3)? *st.begin() : *st.rbegin();
    } 
};