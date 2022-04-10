class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
      for(int i=0;i<ops.size();i++){
          
    
            if(ops[i]=="C"){
                 
               st.pop(); 
                 
            }
           
            else if(ops[i]=="D"){
               
                int x= st.top();
            //    x=x*2;
                st.push(x*2);
            }
            else if(ops[i]=="+"){
                int x=st.top();
                st.pop();
                int y= st.top();
               
                st.push(x);
                st.push(x+y);
            }
            else{
                int x= stoi(ops[i]);
                st.push(x);
            }
           // cout<<st.top()<<endl;
           
           // i++;
        }
        
        int sum=0;
        while(!st.empty()){
            int x=st.top();
             st.pop();
            sum=sum + x;
           
        }
        return sum;
    }
};