class Solution {
public:
    int findMin(vector<int>& arr) {
        // code here
        int n =arr.size();
	    int s=0;
	    int e=n-1;
	    while(s<e){
	        int mid =s+ (e-s)/2;
	        if(arr[mid]<arr[e])
	            e=mid;
	        else
	            s=mid+1;
	    }
	    return arr[s];
	}
    
};