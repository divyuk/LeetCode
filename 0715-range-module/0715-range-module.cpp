class RangeModule {
     map<int, int> m;
public:
    RangeModule() {
        
    }
    
   
    void addRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it != begin(m) && prev(it)->second >= left)
            left = prev(it)->first;
        m.insert({left, removeIntervals(left, right)});
    }
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it != begin(m))
            it = prev(it);
        return left >= it->first && right <= it->second;
    }
    void removeRange(int left, int right) {
        int right1 = removeIntervals(left, right);
        auto it = m.lower_bound(left);
        if (it != begin(m)) {
            right1 = max(right1, prev(it)->second);
            prev(it)->second = min(prev(it)->second, left);
        }
        if (right1 > right)
            m.insert({right, right1});
    }
    int removeIntervals(int l, int r) {
        for (auto it = m.lower_bound(l); it != end(m) && it->first <= r; ) {
            r = max(r, it->second);
            m.erase(it++);
        }
        return r;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */