class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)
            return false;
        int i=0;
        int j=0;
        unordered_map<string,int> mp;
        string res="";
//         while(j<s.length()){
            
//             res+=s[j];
//             cout<<res<<endl;
//             if(res.size()<k){
//                 j++;
//             }
//             else{
//             if(res.size()==k){
//                 mp[res]++;
//             }
//             else if(res.size()>k){
//                 //string t=res.substr(1,res.length());
                
//                 //res=t;
//                 res.erase(res.begin());
//                 mp[res]++;
                
//             }
//                 j++;
//             }
//         }
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        for(int i=0;i<s.length()-k+1;i++){
            string t= s.substr(i,k);
            mp[t]++;
        }
        int x=pow(2,k);
        if(mp.size()==x)
            return true;
        return false;
    }
};