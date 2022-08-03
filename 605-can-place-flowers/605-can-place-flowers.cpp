class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
         if(f.size()==1 && f[0]==0 && n==0){
             return true;
         }
        if(f.size()==1 && f[0]==0){
            n--;
            if(n==0)
                return true;
            return false;
        }
        if(f.size()>=2 && f[0] ==0 && f[1]==0){
            n--;
            f[0]=1;
        }
        int i=1;
        while(i<f.size()-1){
            if(f[i]==1){
                i=i+2;
            }
            else if( f[i-1]==1 && f[i+1]!=1){
                i++;
            }
            else if( f[i-1]!=1 && f[i+1]==1){
                i=i+2;
                
            }
            else if(f[i-1]==1 && f[i+1]==1){
                i=i+3;
            }
            else {
                f[i]=1;
                n--;
                  i=i+2;
                 }
        }
        
        if(f[f.size()-1]==0 && f[f.size()-2]==0){
            n--;
        }
        if(n<=0)
            return true;
        return false;
    }
};