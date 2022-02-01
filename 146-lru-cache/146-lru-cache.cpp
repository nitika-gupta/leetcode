class LRUCache {
public:
    class node{
    public:
    
    
    int key;
    int val;
    node* prev;
    node* next;
    node(int k,int v){
        key= k;
        val=v;
        
    }
    
};
    node* head= new node(-1,-1);
    node* tail = new node(-1,-1);
    
    unordered_map<int,node*> mp;
    
    
    int n;
    
    LRUCache(int capacity) {
        n=capacity;
        head->next=tail;
    tail->prev=head;
    }
    
    void add(node* newnode){
        node* temp= head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
        
        
    }
    void deleten(node* del){
        node* delprev=del->prev;
        node* delnext=del->next;
        delprev->next=del->next;
        delnext->prev=del->prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resn=mp[key];
            int res=resn->val;
            mp.erase(key);
            deleten(resn);
            add(resn);
            mp[key]=head->next;
            return res;
            
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *exist= mp[key];
            mp.erase(key);
            deleten(exist);
            
        }
        if(mp.size()==n){
            mp.erase(tail->prev->key);
            deleten(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


