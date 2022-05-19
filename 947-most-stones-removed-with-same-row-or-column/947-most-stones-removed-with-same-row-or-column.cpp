class Solution {
public:
    int find(int x,vector<int> & par){
        if(par[x]==x)
            return x;
        return par[x]=find(par[x],par);
    }
    
    void uni(int i,int j,vector<int> &par,vector<int>& rank){
        int x=find(i,par);
        int y=find(j,par);
        if(rank[x]<rank[y])
            par[x]=y;
        else if(rank[x]>rank[y])
            par[y]=x;
        else{
            par[x]=y;
            rank[y]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> par(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    uni(i,j,par,rank);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(par[i]==i)
                count++;
        }
        return n-count;
    }
};