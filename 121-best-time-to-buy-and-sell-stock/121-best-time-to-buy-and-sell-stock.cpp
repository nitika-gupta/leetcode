class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int p=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(min>prices[i])
                min=prices[i];
            else if( min< prices[i] && p<prices[i]-min){
                p=prices[i]-min;
                //cout<<"p"<<p;
            }
            
        }
        if(p==INT_MIN)
            return 0;
        return p;
    }
};