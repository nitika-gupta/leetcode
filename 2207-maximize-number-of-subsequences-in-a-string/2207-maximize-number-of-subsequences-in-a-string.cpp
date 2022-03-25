class Solution {
public:
    int fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
    }
    long long maximumSubsequenceCount(string text, string pat) {
        
        unordered_map<int,int> mp1;
        int count1=0;
        int n=text.length();
        long long int val1=0;
        for(int i=n-1;i>=0;i-- ){
            if(text[i]== pat[1]){
                count1++;
            }
            else if(text[i]==pat[0]){
                mp1[i]=count1;
                val1+=count1;
            }
        }
        cout<<val1<<endl;
        unordered_map<int,int> mp2;
        int count2=0;
      //  int n=text.length();
        // int val2=0;
        // for(int i=0;i<n;i++ ){
        //     if(text[i]== pat[0]){
        //         count2++;
        //     }
        //     else if(text[i]==pat[1]){
        //         mp[i]=count2;
        //         val2+=count2;
        //     }
        // }
        
        long long int x=0;
        long long int y=0;
        for(auto it: text){
            if(it==pat[0])
                x++;
            if(it==pat[1])
                y++;
        }
        cout<<x<<" "<<y;
        if(pat[0]==pat[1])
        {
            
            return x*(x+1)/2;
        }
        return max (val1+x,val1+y);

    }
};