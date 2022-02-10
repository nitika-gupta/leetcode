class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int m=popped.size();
        int j=0;
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(pushed[i]);
            
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                ++j;
            }
        }
        return (s.empty());
    }
};