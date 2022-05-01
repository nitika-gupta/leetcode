class Solution {
public:
    bool backspaceCompare(string s, string t) {
      string s1="";
        string s2="";
//         int n=s.size();
//         int m=t.size();
//         int c=0;int c1=0;
//         int i=n-1;int f=0;
//         while(i>=0)
//         {
//             if(s[i]=='#')
//             {
//                 c++;
//                 if(s[i-1]!='#')
//                 {
//                     i=i-2;
//                     // if(i<=-1)
//                     // {
//                     //     f=1;
//                     //     break;
//                     //     //i=-1;
//                     // }
//                     c--;
//                 }
//             }
//             else
//             {
//                 if(c==0)
//                 {
//                     s1+=s[i];
//                 }
//                 else
//                 {
//                     c--;
//                 }
//             }
//             i--;
//         }
//         i=m-1;int g=0;
//         while(i>=0)
//         {
//             if(t[i]=='#')
//             {
//                 c1++;
//                 if(t[i-1]!='#')
//                 {
                    
//                     i=i-2;
//                     // if(i<=-1)
//                     // {
//                     //     g=1;
//                     //     break;
//                     // }
                    
//                     c1--;
//                 }
//             }
//             else
//             {
//                 if(c1==0)
//                 {
//                     s2+=t[i];
//                 }
//                 else
//                 {
//                     c1--;
//                 }
//             }
//             i--;
//         }
//         cout<<s1<<endl;
//         cout<<s2<<endl;
//         if(s1.size()==0 && s2.size()==0){
//            // cout<<"x";
//             return true;
//         }
            
//         if(s1==s2)
//         {
//             return true;
//         }
//         return false;
        
        int c1=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#'){
                c1++;
            }
            else{
                if(c1>0){
                    c1--;
                    continue;
                    
                }
                if(c1==0){
                    s1=s[i]+s1;
                }
            }
        }
         int c2=0;
        for(int i=t.length()-1;i>=0;i--){
            if(t[i]=='#'){
                c2++;
            }
            else{
                if(c2>0){
                    c2--;
                    continue;
                    
                }
                if(c2==0){
                    s2=t[i]+s2;
                }
            }
        }
        cout<<s1<<endl;
        cout<<s2<<endl;
        return (s1==s2);
    }
};