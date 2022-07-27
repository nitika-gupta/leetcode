class NumberContainers {
public:
    unordered_map<int,set<int>> mp1;
    unordered_map<int,int> mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index) != mp2.end()){
          
            mp1[mp2[index]].erase(index);
            
           
        }
        mp2[index]=number;
        mp1[number].insert(index);
    }
    
    int find(int number) {
        if(mp1.find(number)== mp1.end())
            return -1;
        if(mp1[number].size()==0)
            return -1;
        int x = *mp1[number].begin();
        return x;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */