class KthLargest {
public:
    
    int k1;
    priority_queue <int, vector<int>, greater<int> > pq;
    // vector<int> arr;
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        // for(int i=0;i<nums.size();i++){
        //     arr.push_back(nums[i]);
        //     }
        // }
        
        for(auto it: nums){
            pq.push(it);
            if(pq.size()>k1)
                pq.pop();
        }
    }
    
    
    int add(int val) {
       //  priority_queue <int, vector<int>, greater<int> > pq;
       // arr.push_back(val);
       //  for(int i=0;i<arr.size();i++){
       //      pq.push(arr[i]);
       //      if(pq.size()>k1){
       //          pq.pop();
       //      }
       //  }
        pq.push(val);
        if(pq.size()>k1)
            pq.pop();
       
        
    
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */