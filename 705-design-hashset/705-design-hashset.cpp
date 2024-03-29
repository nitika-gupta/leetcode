class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        vector<int> v1(1000001,0);
        v=v1;
    }
    
    void add(int key) {
        v[key]++;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        if(v[key]!=0)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */