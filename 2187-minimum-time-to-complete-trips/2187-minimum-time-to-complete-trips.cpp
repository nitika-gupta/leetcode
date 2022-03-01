class Solution {
public:
    long long isvalid(vector<int>& time, long long mid){
        long long count=0;
        for(auto it: time){
            count+=mid/it;   
        }
        return count;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long h = (long long) time[0]* totalTrips;
        long long l=1;
        
        while(l<h){
            
            long long mid= l+(h-l)/2;
            long long  x=isvalid(time,mid);
            if(x>=totalTrips)
                h=mid;
            else
                l=mid+1;
        }
        return l;
    }
};