class Solution {
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),[](const auto &a,const auto & b)->bool{
            return a[1]<b[1];
        });
        
        // for(int i=0;i<courses.size();i++){
        //     cout<<courses[i][0]<<" "<<courses[i][1]<<endl;
        // }
      //  if(courses.size()==1){
        //    return (courses[0][0]<=courses[0][1]);
        //}
        
        priority_queue<pair<int,int>> pq;
        int time=0;
        int mx=INT_MIN;
        for(int i=0;i<courses.size();i++){
            if(time+courses[i][0]<= courses[i][1]){
                pq.push({courses[i][0],courses[i][1]});
                time+=courses[i][0];
            }
            else{
                int s=pq.size();
             //   mx=max(mx,s);
                if(!pq.empty() && pq.top().first > courses[i][0]){
                    int x=pq.top().first;
                    pq.pop();
                    time-=x;
                    pq.push({courses[i][0],courses[i][1]});
                   time+=courses[i][0];
                }
                
                
            }
        
        }
       
        return  pq.size();
    }
};