class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          
        priority_queue<int> h;
        for(auto it : stones){
            h.push(it);
            
        }
      
        while(h.size()>1){
            if(h.size()==1)
                return h.top();
            if(h.size()==0)
                return 0;
            int x= h.top();
            h.pop();
            
            int y = h.top();
                h.pop();
            if(x!=y){
                h.push(x-y);
            }
            else{
                h.push(0);
            }
               
            
            
            }
        return h.top();
       
        
    }
};