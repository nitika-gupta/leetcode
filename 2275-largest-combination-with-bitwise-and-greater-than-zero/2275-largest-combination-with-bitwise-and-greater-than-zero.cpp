class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        long long int x=1;
        long long  int res=-1;
        for(int i=1;i<=24;i++){
            long long int count=0;
            for(int j=0;j<candidates.size();j++){
                //cout<<x<<" ";
                long long int z=x&candidates[j];
               // cout<<z<<" ";
                if(z==x)
                    count++;
              
            }
            //cout<<endl; 
            //cout<<"count "<<count<<" "<<endl;
            res=max(count,res);
            x=x<<1;
        }
        return res;
    }
};