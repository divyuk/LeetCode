class RandomizedSet {
public:
    unordered_set<int>uset;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(uset.find(val)!=uset.end())
            return 0;
        uset.insert(val);
        return 1;
    }
    
    bool remove(int val) {
       if(uset.find(val)!=uset.end()){
            uset.erase(val);
            return 1;
       }
        return 0;
    }
    
    int getRandom() {
        int size = uset.size();
        int random = rand()%size;
        auto it = uset.begin();
        advance(it,random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */