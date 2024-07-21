class LFUCache {
public:
    class llist{
        public:
        int key;
        int value;
        llist *next;
        llist *prev;
    };
    int C;
    map<int,int>freq;
    map<int,llist*>mp;
    map<int,pair<llist*,llist*>>fk;
    void add(int cnt){
        llist* head = new llist();
        llist* tail = new llist();
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
        fk[cnt] = {head,tail};
    }
    void insrt(llist* node, int cnt){
        llist* head = fk[cnt].first;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void dele(llist* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        llist* head = fk[freq[node->key]].first;
        if(head->next->next==NULL){
            fk.erase(freq[node->key]);
        }
    }
    LFUCache(int capacity) {
        C = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        llist *node = mp[key];
        llist* nd = new llist();
        nd->key = node->key;
        nd->value = node->value;
        dele(node);
        freq[key]++;
        if(fk.find(freq[key])==fk.end()) add(freq[key]);
        insrt(nd,freq[key]);
        mp[key] = nd;
        return nd->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            llist* node = mp[key];
            dele(node);
        }
        else if(mp.size()==C){
            auto itr = fk.begin();
            llist* tail = itr->second.second;
            llist* node = tail->prev;
            node->prev->next = node->next;
            tail->prev = node->prev;
            mp.erase(node->key);
            freq.erase(node->key);
        }
        freq[key]++;
        if(fk.find(freq[key])==fk.end()) add(freq[key]);
        llist* nd = new llist();
        nd->key = key;
        nd->value = value;
        insrt(nd,freq[key]);
        mp[key] = nd;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */