class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
            return true;
        
        
        int n=s1.length();
        
        int count=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
                v.push_back(i);
            }
        }
        if(count>2 || count==1)
            return false;
        
        swap(s1[v[0]],s1[v[1]]);
        if(s1==s2)
            return true;
        return false;
    }
};