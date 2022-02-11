class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#')
                s1.push(s[i]);
            else if(!s1.empty()){
                s1.pop();
            }
        }
        
        string temp1="";
        while(!s1.empty()){
            temp1+=s1.top();
            s1.pop();
        }
        reverse(temp1.begin(),temp1.end());
        
        for(int i=0;i<t.length();i++){
            if(t[i]!='#')
                s2.push(t[i]);
            else if(!s2.empty()){
                s2.pop();
            }
        }
         string temp2="";
        while(!s2.empty()){
            temp2+=s2.top();
            s2.pop();
        }
        reverse(temp2.begin(),temp2.end());
        if(temp1==temp2)
            return true;
        return false;
        
    }
};