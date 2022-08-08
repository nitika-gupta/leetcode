class Solution {
public:
    bool judgeCircle(string m) {
        
//         stack<char> st;
//         for(int i=0;i<moves.length();i++){
//             if(st.empty()){
//                 st.push(moves[i]);
//             }
//             else{
//                 if(st.top()=='U' && moves[i] == 'D')
//                     st.pop();
//                 else if(st.top()=='D' && moves[i]=='U')
//                     st.pop();
//                 else if(st.top()=='L' && moves[i] == 'R')
//                     st.pop();
//                 else if(st.top()=='R' && moves[i]=='L')
//                     st.pop();
//                 else{
//                     st.push(moves[i]);
//                 }
                
                
//             }
//         }
//         return st.empty();
        int r=0,c=0;
        for(int i=0;i<m.length();i++){
            if(m[i]=='U'){
                r=r-1;
            }
            else if(m[i]=='R'){
                c=c+1;
            }
            else if(m[i] =='L'){
                c=c-1;
            }
            else {
                r=r+1;
            }
        }
        if(r==0 &&c==0)
            return true;
        return false;
    }
};