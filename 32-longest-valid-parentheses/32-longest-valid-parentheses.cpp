class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxx=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len =i-st.top();
                    maxx=max(len, maxx);
                }
            }
        }
        return maxx;
        
    }
};