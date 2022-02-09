class Solution {
public:
      int  getMaxArea(vector<int>& arr , int n)
    {
        // Your code here
        stack<pair<int  ,int>> st;
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            if(st.empty())
                v.push_back(n);
            else if(!st.empty() && st.top().first<arr[i]){
                v.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first >=arr[i]){
                while(!st.empty() && st.top().first>= arr[i]){
                    st.pop();
                    
                }
                if(st.empty())
                    v.push_back(n);
                else
                    v.push_back(st.top().second);
            }
            
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        
        stack<pair<int,int>> s;
        vector<int> v1;
        for(int i=0;i<n;i++){
            if(s.empty())
                v1.push_back(-1);
            else if(!st.empty() && s.top().first<arr[i]){
                v1.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first>= arr[i]){
                while(!s.empty() && s.top().first>= arr[i]){
                    s.pop();
                    
                }
                if(s.empty())
                    v1.push_back(-1);
                else
                    v1.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
        }
          vector<int> width(n);
        vector<int> area(n);
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            width[i]=v[i]-v1[i]-1;
            area[i]=arr[i]*width[i];
            if(max<area[i])
            max=area[i];
        }
        return max;
      }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        
        vector<int> hist(n,0);
        
        int mx= 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')
                    hist[j]=0;
                
                else
                    hist[j]+=1;
                
            }
            mx=max(mx,getMaxArea(hist,n) );
        }
        return mx;
        
    }
};