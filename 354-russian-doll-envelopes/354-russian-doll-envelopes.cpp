class Solution {
public:
    
    int f(int i,vector<vector<int>>& e,int prev,vector<vector<int>> &dp){
        if(i==e.size())
            return 0;
        
        if(prev!=-1)
            if(dp[i][prev]!=-1)
                return dp[i][prev];
        
        int x=0,y=0;
        if(prev==-1 || (e[prev][1]<e[i][1] && e[prev][0]!=e[i][0]))
            x=1 + f(i+1,e,i,dp);
        
        y=f(i+1,e,prev,dp);
        if(prev!=-1)
            return dp[i][prev]=max(x,y);
        return max(x,y);
    }
      static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
     int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),cmp);
        
        int n=e.size();
          
        vector<int> lis;
        
        for(int i = 0;i<e.size();i++){
            int ele = e[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        
        return lis.size();
    }
    
};