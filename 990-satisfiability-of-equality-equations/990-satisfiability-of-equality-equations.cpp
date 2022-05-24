class Solution {
public:
    int fpar(int x,vector<int>& par){
        if(par[x]==x)
            return x;
        return par[x]=fpar(par[x],par);
    }
    void uni(int a,int b,vector<int> &rank,vector<int> & par){
     //cout<<a<<" "<<b;
        int u=fpar(a,par);
         
        int v=fpar(b,par);
          
        if(rank[u]<rank[v])
            par[u]=v;
        else if(rank[v]<rank[u])
            par[v]=u;
        else{
            par[u]=v;
            rank[v]++;
        
        }   
        return;
    }
    bool equationsPossible(vector<string>& equations) {
       vector<int> par(26);
        for(int i=0;i<26;i++)
            par[i]=i;
        
    
        
        vector<int> rank(26,0);
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                
               
                 // cout<<(int)equations[i][3]-97;
                uni( (int)equations[i][0]-97,(int)equations[i][3]-97,rank,par);
                cout<<"hi";
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                if(fpar((int)equations[i][0]-97,par)==fpar((int)equations[i][3]-97,par))
                    return false;
        }
        }
        return true;
    }
};