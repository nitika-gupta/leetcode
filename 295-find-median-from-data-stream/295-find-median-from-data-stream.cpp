class MedianFinder {
public:
    
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        if(pq1.empty() || pq1.top()>num){
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }
        
        if(pq2.size() >pq1.size()+1){
            pq1.push(pq2.top());
            pq2.pop();
            
        }
        else if(pq2.size()+1 <pq1.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        double median;
        if(pq2.size()==pq1.size()){
            int a= pq1.top();
            int b= pq2.top();
             median= (double)((double)a+(double)b)/2.0;
        }
        else {
            if(pq2.size()<pq1.size())
                median= pq1.top();
            else{
                median= pq2.top();
            }
        }
        return median;
    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */