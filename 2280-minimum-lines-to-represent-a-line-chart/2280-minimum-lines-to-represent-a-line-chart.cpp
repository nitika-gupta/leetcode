class Solution {
public:
   // int minimumLines(vector<vector<int>>& s) {
   //      if(s.size()==1)
   //          return 0;
   //      sort(s.begin(),s.end());
   //      auto m =(long double) (s[1][1]-s[0][1])/(s[1][0]-s[0][0]);
   //      cout<<m<<" ";
   //      int c=1;
   //      for(int i=2;i<s.size();i++){
   //          auto cm=(long double) (s[i][1]-s[i-1][1])/(s[i][0]-s[i-1][0]);
   //          cout<<cm<<" ";
   //          if(cm!=m)
   //              c++; 
   //          m=cm;
   //      }
   //      return c;
   //        }
        int minimumLines(vector<vector<int>>& stockPrices)
    {   if(stockPrices.size()==1)
        return 0;
        sort(stockPrices.begin(),stockPrices.end());
        auto a=(long double)stockPrices[1][1]-(long double)stockPrices[0][1];
        auto b=(long double)stockPrices[1][0]-(long double)stockPrices[0][0];
        auto m=(long double)(a/b);
        int c=1;
     cout<<m<<" ";
        for(int i=2;i<stockPrices.size();i++)
        {
            auto x=(long double)(stockPrices[i][1]-stockPrices[i-1][1])/(stockPrices[i][0]-stockPrices[i-1][0]);
            //auto x=(long double)(e/d);
            if(m!=x)
            {
                c++;
              
             
            }
               m=x;
              cout<<m<<" ";
        }
        return c;
    }
    
};