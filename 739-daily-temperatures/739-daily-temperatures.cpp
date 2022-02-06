class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res;
        int n=temperatures.size()-1;
        for(int i=n;i>=0;i--){
            if(st.empty())
                res.push_back(0);
            else if(st.size()>0 &&st.top().first>temperatures[i]){
                res.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first<= temperatures[i]){
                while(st.size()>0 && st.top().first<= temperatures[i]){
                    st.pop();
                }
                if(st.size()==0)
                    res.push_back(0);
                else{
                    res.push_back(st.top().second);
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            if(res[i]==0)
                continue;
            res[i]=res[i]-i;
        }
        return res;
    }
};