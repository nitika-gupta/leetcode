class Solution {
public:

    double myPow(double x, int n) {
        
        if(n==0)
            return 1;
        
        double ans=1.0;
        
        long long int t=n;
        if(t<0){
            t=-1*t;
        }
        
        while(t){
            if(t%2==0){
                x=x*x;
                t=t/2;
            }
            else{
                ans=ans*x;
                t=t-1;
            }
            
        }
        
        if(n<0){
            return (double)1.0/(double)ans;
        
        }
    
            return double(ans);
        
    }
};