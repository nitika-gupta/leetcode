class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i=s.size()-2;
        
        while(i>=0 && s[i]>=s[i+1]){
            i--;
        }
        
        if(i==-1)
            return -1;
        
        int j=s.size()-1;
        while(s[i]>=s[j])
            j--;
        
        swap(s[i],s[j]);
        
        reverse(s.begin()+i+1,s.end());
        long res=stol(s);
        return ((res>INT_MAX || res==n)?-1:res);
        
    }
};