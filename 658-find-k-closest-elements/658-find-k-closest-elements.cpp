class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> heap;
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            heap.push({abs(arr[i]-x),arr[i]});
            if(heap.size()>k){
                heap.pop();
            }
            
        }
        
        while(heap.size()!=0){
            res.push_back(heap.top().second);
            heap.pop();
        }
        sort(res.begin(),res.end());
        return res;
        
        
    }
};