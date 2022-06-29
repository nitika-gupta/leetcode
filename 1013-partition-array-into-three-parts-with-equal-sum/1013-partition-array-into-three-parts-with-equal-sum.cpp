class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        
        
        if(sum!=0 && sum%3!=0)
            return false;
        
        int x=sum/3;
        int partition =0;
        //cout<<x<<" ";
        int temp=0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            if(temp==x){
                cout<<temp<<" ";
                partition++;
                temp=0;
            }
        }
        if(sum==0 && partition >=3)
            return true;
        if(partition >= 3)
            return true;
        return false;
    }
};