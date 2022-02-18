class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            
            
                while(!st.empty() && num[i]<st.top() && k>0){
                    st.pop();
            k--;}
                //st.push(num[i]);
            
           
            if(st.empty() && num[i]=='0')
                continue;
            
                st.push(num[i]);
            
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty())
            return "0";
        string s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};