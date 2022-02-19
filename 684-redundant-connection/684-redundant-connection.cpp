class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x)
            return x;
        return find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        parent.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        vector<int> res(2,0);
        for(auto it: edges){
            int x= find(it[0]);
            int y=find(it[1]);
            if(x!=y){
                parent[x]=y;
            }
            else{
                res[0]=it[0];
                res[1]=it[1];
            }
        }
        return res;
    }
};