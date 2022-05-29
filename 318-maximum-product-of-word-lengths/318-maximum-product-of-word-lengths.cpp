class Solution {
public:
    int solve(string s){
        int x=0;
        //cout<<s;
        for(int j=0;j<s.length();j++){
           // cout<<s[j]<<" ";
            
            //cout<<int(a);
            int v=s[j];
          //  cout<<v<< " ";
            int i=v-97;
         // cout<<i<<" ";
            x|=1<<(i);
           // cout<<x<<endl;
        }
        return x;
    }
    int maxProduct(vector<string>& words) {
        vector<int> st(words.size(),0);
        
        for(int i=0;i<words.size();i++){
            st[i]=solve(words[i]);
           // cout<<st[i]<<" ";
        }
        
        int mx=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                //cout<<st[i]<<" "<<st[j]<<" ";
                if( (st[i]&st[j])==0){
                   
                    int a=words[i].size()* words[j].size();
                    //cout<<a<<" ";
                    
                    mx=max(a,mx);
                }
                
            }
        }
      
        return mx;
    }
};