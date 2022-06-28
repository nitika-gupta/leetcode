class Solution {
public:
    
    int merge(vector<int>& nums,int l,int mid,int h){
        int ls=mid-l+1;
        int rs=h-mid;
        vector<int> left(ls);
        vector<int> right(rs);
        
      
        for(int i=0;i<ls;i++){
            left[i]=nums[l + i];
            
        }

        for(int i=0;i<rs;i++){
            right[i]=nums[mid+1 +i];
        }
        
        
        int count=0;
        int x=0;
        int y=0;
        int z=l;
        
        int p=mid+1;
        int q=l;
        while(q<=mid && p<=h){
            if(nums[q]>2*(long long )nums[p]){
                count+=(mid-q+1);
                p++;
            }
            else{
                q++;
            }
        }
        while(x<ls && y<rs ){
            if(left[x]>right[y]){
                
                nums[z++]= right[y++];
            }
            else{
                nums[z++]=left[x++];
            }   
        }
         while(x<ls){
                nums[z++]=left[x++];
            }
            while(y<rs){
                nums[z++]=right[y++];
            }
        return count;
        
    }
    int mergesort(vector<int> & nums, int l,int h){
        
        int count =0;
        if(l>=h)
            return count;
        int mid=l+(h-l)/2;
        count+=mergesort(nums,l,mid);
        count+=mergesort(nums,mid+1,h);
        count+=merge(nums,l,mid,h);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergesort(nums,0,nums.size()-1);
        
    }
};