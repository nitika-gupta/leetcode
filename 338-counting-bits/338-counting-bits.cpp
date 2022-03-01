class Solution {
public:
    int count(int n){
        int c=0;
        while(n){
            if(n%2!=0)
                c++;
            n=n/2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(count(i));
        }
        return res;
    }
};